/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:29:35 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/13 16:23:16 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//takes cmd1 and split it
//takes stin and redirect it to my new infile fd
//takes stdout and redirect it to my fd[1] (writing)
//close fd[0] (reading) to avoid issues
void	child_process(t_p data, char *cmd, char **envp)
{
	char	*path;
	char	**cmd1;

	cmd1 = ft_split(cmd, ' ');
	if (cmd1[0] == NULL)
		exit(EXIT_FAILURE);
	path = get_path(cmd1[0], envp);
	dup2(data.infile_fd, 0);
	dup2(data.fd[1], 1);
	close(data.fd[0]);
	execve(path, cmd1, envp);
}

//takes stdout and redirect it to my new outfile fd
//takes stdin and redirect it to my fd[0] (reading)
//close fd[1] (writing) to avoid issues
void	parent_process(t_p data, char *cmd, char **envp)
{
	char	*path;
	char	**cmd2;

	cmd2 = ft_split(cmd, ' ');
	if (cmd2[0] == NULL)
		exit(EXIT_FAILURE);
	path = get_path(cmd2[0], envp);
	dup2(data.outfile_fd, 1);
	dup2(data.fd[0], 0);
	close(data.fd[1]);
	execve(path, cmd2, envp);
}
