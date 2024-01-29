/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:42:45 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/29 01:38:11 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../LIBFT/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_p
{
	int		infile_fd;
	int		outfile_fd;
	int		fd[2];
	pid_t	pid;
	char	**cmd1;
	char	**cmd2;
	char	*path;
}	t_p;

void    init_cmds(char **argv, t_p *data);

int		check_argc(int argc);
int		check_infile(char *file);
int		check_outfile(char *file);
char	**get_env_path(char **envp);
char	*get_path(char *cmd, char **env);
void	check_cmds(char **cmds);
void	check_path(char *path, char **cmds);
void	child_process(t_p data, char **env);
void	parent_process(t_p data, char **env);

#endif
