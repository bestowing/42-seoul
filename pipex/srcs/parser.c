/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 03:50:13 by chelee            #+#    #+#             */
/*   Updated: 2021/06/25 01:42:08 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_path_value(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strlen(envp[i]) >= 4 && envp[i][0] == 'P'
			&& envp[i][1] == 'A' && envp[i][2] == 'T' && envp[i][3] == 'H')
			return (i);
		i++;
	}
	return (FAIL);
}

static int	get_path_list_size(char **chunk)
{
	int	len;

	len = 0;
	while (chunk[len])
		len++;
	return (len);
}

static int	allo_cmd(t_envp *env, t_cmd *cmd)
{
	cmd->path = malloc(sizeof(char *) * env->path_size);
	if (!cmd->path)
		return (FAIL);
	return (SUCCESS);
}

int			parse_envp(char *envp[], t_envp *env, t_cmd *cmd)
{
	char	**chunk;
	int		i;

	i = get_path_value(envp);
	if (i == FAIL)
		return (FAIL);
	chunk = ft_split(envp[i] + 5, ':');
	if (!chunk)
		return (FAIL);
	env->path_list = chunk;
	env->path_size = get_path_list_size(chunk);
	if (allo_cmd(env, cmd) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
