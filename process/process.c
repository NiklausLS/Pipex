/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:29:35 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/26 18:20:58 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//takes cmd1 and split it
//takes stin and redirect it to my new infile fd
//takes stdout and redirect it to my fd[1] (writing)
//close fd[0] (reading) to avoid issues
void	child_process(t_p data, char *cmd, char **env)
{
	char	*path;
	char	**cmd1;

	cmd1 = ft_split(cmd, ' ');
	path = get_path(cmd1[0], env);
	check_path(path, cmd1);
	check_cmds(path, cmd1);
	dup2(data.infile_fd, 0);
	dup2(data.fd[1], 1);
	close(data.fd[0]);
	if (execve(path, cmd1, env) == -1)
	{
		write(2, "Error : execve\n", 16);
		exit(EXIT_FAILURE);
	}
}

//takes stdout and redirect it to my new outfile fd
//takes stdin and redirect it to my fd[0] (reading)
//close fd[1] (writing) to avoid issues
void	parent_process(t_p data, char *cmd, char **env)
{
	char	*path2;
	char	**cmd2;

	cmd2 = ft_split(cmd, ' ');
	path2 = get_path(cmd2[0], env);
	check_path(path2, cmd2);
	check_cmds(path2, cmd2);
	dup2(data.outfile_fd, 1);
	dup2(data.fd[0], 0);
	close(data.fd[1]);
	if (execve(path2, cmd2, env) == -1)
	{
		write(2, "Error : execve\n", 16);
		exit(EXIT_FAILURE);
	}
}
