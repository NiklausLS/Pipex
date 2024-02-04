/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:29:35 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/04 23:58:22 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//takes cmd1 and split it
//takes stin and redirect it to my new infile fd
//takes stdout and redirect it to my fd[1] (writing)
//close fd[0] (reading) to avoid issues
void	child_process(t_p *data, char **env, char **argv)
{
	data->infile_fd = check_infile(argv[1]);
	data->cmd1 = ft_split(argv[2], ' ');
	data->path1 = get_path(data->cmd1[0], env);
	dup2(data->infile_fd, 0);
	dup2(data->fd[1], 1);
	close(data->fd[0]);
	if (execve(data->path1, data->cmd1, env) == -1)
	{
		write(2, "command not found\n", 19);
		free_cmd1(data);
		exit(EXIT_FAILURE);
	}
}

//takes stdout and redirect it to my new outfile fd
//takes stdin and redirect it to my fd[0] (reading)
//close fd[1] (writing) to avoid issues
void	parent_process(t_p *data, char **env, char **argv)
{
	data->outfile_fd = check_outfile(argv[4]);
	data->cmd2 = ft_split(argv[3], ' ');
	data->path2 = get_path(data->cmd2[0], env);
	dup2(data->outfile_fd, 1);
	dup2(data->fd[0], 0);
	close(data->fd[1]);
	if (execve(data->path2, data->cmd2, env) == -1)
	{
		write(2, "command not found\n", 19);
		free_cmd2(data);
		exit(EXIT_FAILURE);
	}
}
