/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 02:27:26 by chelee            #+#    #+#             */
/*   Updated: 2021/06/26 14:57:22 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		redirect_in(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror(file_name);
		exit(1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (close(fd) == -1)
	{
		perror("close");
		exit(1);
	}
	return ;
}

void		redirect_out(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file_name);
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (close(fd) == -1)
	{
		perror("close");
		exit(1);
	}
	return ;
}

static void	clear_tmp_file(void)
{
	char	**argv;
	pid_t	pid;

	if ((argv = malloc(sizeof(char *) * 3)) == 0)
	{
		perror("malloc");
		exit(1);
	}
	argv[0] = "-f";
	argv[1] = "./tmp";
	argv[2] = NULL;
	pid = fork();
	if (pid == 0)
		execve("/bin/rm", (char *const *)argv, NULL);
	else if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	return ;
}

static void	write_tmp_file(int fd, const char *limiter)
{
	int		stat;
	char	*buf;

	buf = NULL;
	write(STDOUT_FILENO, "heredoc> ", 9);
	while ((stat = get_next_line(STDIN_FILENO, &buf)) != 0)
	{
		if (stat == -1)
			exit(1);
		if (ft_strcmp(buf, limiter) == 0)
			break ;
		write(STDOUT_FILENO, "heredoc> ", 9);
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
	}
	return ;
}

void		heredoc(const char *limiter)
{
	int		fd;

	fd = open("./tmp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("./tmp");
		exit(1);
	}
	write_tmp_file(fd, limiter);
	if (close(fd) == -1)
	{
		perror("close");
		exit(1);
	}
	redirect_in("./tmp");
	clear_tmp_file();
	return ;
}
