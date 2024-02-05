/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:42:45 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/05 12:59:21 by nileempo         ###   ########.fr       */
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
	char	*path1;
	char	*path2;
}	t_p;

void	init_struct(t_p *data);
void	free_cmd1(t_p *data);
void	free_cmd2(t_p *data);
void	free_tab(char **tab);
void	free_path(t_p *data);

int		check_argc(int argc);
int		check_infile(char *file);
int		check_outfile(char *file);
void	check_if_dir(char *cmd);
void	check_cmd(char *cmd);
char	**split_and_join_path(char **envp);
char	*check_path(char *cmd, char **env);
void	child_process(t_p *data, char **env, char **argv);
void	parent_process(t_p *data, char **env, char **argv);

#endif
