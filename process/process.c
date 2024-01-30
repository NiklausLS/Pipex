/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:29:35 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/30 16:28:29 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//takes cmd1 and split it
//takes stin and redirect it to my new infile fd
//takes stdout and redirect it to my fd[1] (writing)
//close fd[0] (reading) to avoid issues
void	child_process(t_p data, char **env)
{
	data.path1 = get_path(data.cmd1[0], env);
	check_path(data.path1);
	dup2(data.infile_fd, 0);
	dup2(data.fd[1], 1);
	close(data.fd[0]);
	if (execve(data.path1, data.cmd1, env) == -1)
	{
		write(2, "Error : execve\n", 16);
		free(data.path1);
		exit(EXIT_FAILURE);
	}
}

//takes stdout and redirect it to my new outfile fd
//takes stdin and redirect it to my fd[0] (reading)
//close fd[1] (writing) to avoid issues
void	parent_process(t_p data, char **env)
{
	data.path2 = get_path(data.cmd2[0], env);
	check_path(data.path2);
	dup2(data.outfile_fd, 1);
	dup2(data.fd[0], 0);
	close(data.fd[1]);
	if (execve(data.path2, data.cmd2, env) == -1)
	{
		write(2, "Error : execve\n", 16);
		free(data.path2);
		exit(EXIT_FAILURE);
	}
}
