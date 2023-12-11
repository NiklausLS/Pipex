/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:42:45 by nileempo          #+#    #+#             */
/*   Updated: 2023/12/11 09:52:57 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef	struct	s_p
{
	int		file1_fd;
	int 	file2_fd;
	int		fd[2];
	pid_t	pid;
	char	**cmd1;
	char	**cmd2;
}	t_p;

int check_argc(int argc);
int	check_file(char *file);
int check_open(char *file, int flag);

char	**ft_split(char const *s, char c);

#endif
