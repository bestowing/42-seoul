/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 01:21:02 by chelee            #+#    #+#             */
/*   Updated: 2021/07/18 10:56:25 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	connect_pipe(int pipefd[2], int io)
{
	int	idx;

	idx = (io + 1) % 2;
	if (dup2(pipefd[io], io) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (close(pipefd[idx]) == -1)
	{
		perror("close pipefd");
		exit(1);
	}
	return ;
}

static void	wait_child_process(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid");
		exit(1);
	}
	if (WIFEXITED(status) == 0)
		exit(1);
	return ;
}

static void	handle_heredoc(char *argv[], t_cmd cmd, t_envp env, int fildes[2])
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		wait_child_process(pid);
		redirect_out(argv[FILE2 + 1]);
		connect_pipe(fildes, STDIN_FILENO);
		run_cmd(argv[CMD2 + 1], &cmd, env);
	}
	else if (pid == CHILD)
	{
		heredoc(argv[LIMITER]);
		connect_pipe(fildes, STDOUT_FILENO);
		run_cmd(argv[CMD1 + 1], &cmd, env);
	}
	else
	{
		perror("fork");
		exit(1);
	}
	return ;
}

static void	handle_redirect(char *argv[], t_cmd cmd, t_envp env, int fildes[2])
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		wait_child_process(pid);
		redirect_out(argv[FILE2]);
		connect_pipe(fildes, STDIN_FILENO);
		run_cmd(argv[CMD2], &cmd, env);
	}
	else if (pid == CHILD)
	{
		redirect_in(argv[FILE1]);
		connect_pipe(fildes, STDOUT_FILENO);
		run_cmd(argv[CMD1], &cmd, env);
	}
	else
	{
		perror("fork");
		exit(1);
	}
	return ;
}

int			main(int argc, char *argv[], char *envp[])
{
	t_cmd	cmd;
	t_envp	env;
	int		is_heredoc;
	int		fildes[2];

	if (pipe(fildes))
	{
		perror("pipe");
		exit(1);
	}
	is_heredoc = FALSE;
	if (argc >= 2 && ft_strcmp(argv[FILE1], "here_doc") == 0)
		is_heredoc = TRUE;
	if ((is_heredoc && argc < 6) || (!(is_heredoc) && argc < 5))
		exit(1);
	if (init_cmd(envp, &env, &cmd))
		exit(1);
	if (is_heredoc)
		handle_heredoc(argv, cmd, env, fildes);
	else
		handle_redirect(argv, cmd, env, fildes);
	return (0);
}
