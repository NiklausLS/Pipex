/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:42:45 by nileempo          #+#    #+#             */
/*   Updated: 2023/08/15 15:50:28 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_p
{
	int	infile;
	int	outfile;
	int	fd[2];
	char	**cmd1;
	char	**cmd2;
}	t_p;

int main(int argc, char **argv);

int check_argc(int argc);
int check_open(char *file, int flags);


#endif
