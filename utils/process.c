/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:29:35 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/12 23:19:47 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//takes stin and redirect it to my new infile fd
//takes stdout and redirect it to my fd[1] (writing)
//close fd[0] (reading) to avoid issues
void	child_process(t_p data, char *cmd, char **envp)
{
	char	*path;
	char	**cmd1;
	
	puts("CHILD PROCESS\n");
	cmd1 = ft_split(cmd, ' ');
	int i = 0;
	while (cmd1[i])
	{
		printf("cmd1[%d] = %s\n", i, cmd1[i]);
		i++;
	}
	path = get_path(cmd1[0], envp);
	printf("child : path of %s = %s\n", cmd1[0], path);
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
	
	puts("PARENT PROCESS\n");
	cmd2 = ft_split(cmd, ' ');
	int i = 0;
	while (cmd2[i])
	{
		printf("cmd2[%d] = %s\n", i, cmd2[i]);
		i++;
	}
	path = get_path(cmd2[0], envp);
	printf("parent : path of %s = %s\n", cmd2[0], path);
	dup2(data.outfile_fd, 1);
	dup2(data.fd[0], 0);
	close(data.fd[1]);
	execve(path, cmd2, envp);
}
