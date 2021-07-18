/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 01:21:19 by chelee            #+#    #+#             */
/*   Updated: 2021/06/26 14:39:04 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

# define SUCCESS		0
# define FAIL			-1
# define TRUE			1
# define FALSE			0

# define CHILD			0

# define FILE1			1
# define FILE2			4
# define CMD1			2
# define CMD2			3
# define LIMITER		2

# define BUFFER_SIZE	1024

typedef struct		s_envp
{
	int				path_size;
	char			**path_list;
}					t_envp;

typedef struct		s_cmd
{
	const char		**path;
	char * const	*argv;
	char * const	*envp;
}					t_cmd;

typedef struct		s_content
{
	char			*buff;
	int				index;
	int				len;
}					t_content;

/*
**	redirection.c
*/
void				redirect_in(const char *file_name);
void				redirect_out(const char *file_name);
void				heredoc(const char *limiter);

/*
**	cmd_handler.c
*/
int					init_cmd(char *envp[], t_envp *env, t_cmd *cmd);
void				run_cmd(const char *cmd, t_cmd *command, t_envp env);

/*
**	parser.c
*/
int					parse_envp(char *envp[], t_envp *env, t_cmd *cmd);

/*
**	ft_library.c
*/
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin_with_char(const char *s1,
						const char *s2, char c);
int					ft_strcmp(const char *s1, const char *s2);

/*
**	ft_library_cont.c
*/
char				**ft_split(const char *s, char c);
int					ft_strlen(const char *s);

/*
**	get_next_line.c
*/
int					get_next_line(int fd, char **line);

#endif
