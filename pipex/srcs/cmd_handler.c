/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 04:45:38 by chelee            #+#    #+#             */
/*   Updated: 2021/06/26 14:56:22 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_cmd(const char *cmd, t_cmd *command, t_envp env)
{
	char	**chunk;
	int		i;

	i = 0;
	chunk = ft_split(cmd, ' ');
	if (!chunk)
		exit(1);
	while (i < env.path_size)
	{
		command->path[i] =
			ft_strjoin_with_char(env.path_list[i], chunk[0], '/');
		if (!command->path[i])
			exit(1);
		i++;
	}
	command->argv = (char *const *)chunk;
	return ;
}

void		run_cmd(const char *cmd, t_cmd *command, t_envp env)
{
	int	i;

	i = 0;
	set_cmd(cmd, command, env);
	while (i < env.path_size)
	{
		execve(command->path[i], command->argv, command->envp);
		i++;
	}
	perror(command->argv[0]);
	exit(1);
	return ;
}

static void	clean_memory(t_cmd *cmd, t_envp *env)
{
	int	i;

	i = 0;
	while (i < env->path_size)
	{
		if (env->path_list[i])
			free(env->path_list[i]);
		i++;
	}
	if (env->path_list)
		free(env->path_list);
	if (cmd->path)
		free(cmd->path);
	return ;
}

int			init_cmd(char *envp[], t_envp *env, t_cmd *cmd)
{
	env->path_size = 0;
	env->path_list = 0;
	cmd->path = 0;
	cmd->argv = 0;
	cmd->envp = 0;
	if (parse_envp(envp, env, cmd) == FAIL)
	{
		clean_memory(cmd, env);
		return (FAIL);
	}
	return (SUCCESS);
}
