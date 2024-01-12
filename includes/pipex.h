/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:42:45 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/12 22:41:53 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../LIBFT/libft.h"
# include <unistd.h>
# include <stdio.h>
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
//	char	**cmd;
	char	**env;
}	t_p;

int		check_argc(int argc);
int		check_infile(char *file);
int		check_outfile(char *file);
char	**get_env_path(char **envp);
//char	**get_cmd(char *cmd);
char	*get_path(char *cmd, char **envp);
void	child_process(t_p data, char *cmd, char **envp);
void	parent_process(t_p data, char *cmd, char **envp);

#endif