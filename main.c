/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:41:21 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/12 22:42:24 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_p	data;
	
	check_argc(argc);
	data.infile_fd = check_infile(argv[1]);
	data.outfile_fd = check_outfile(argv[4]);
	//data.cmd1 = get_cmd(argv[2]);
	//data.cmd2 = get_cmd(argv[3]);
	envp = get_env_path(envp);
	//data.path = get_path(data);
	//data.path2 = get_path(data);
	//printf("data.path = %s\n", data.path);

	//printf("env = %s\n", data.env);
	//printf("CMD1 = %s\n", data.cmd1[0]);
	//printf("CMD2 = %s\n", data.cmd2[0]);

	//data.path = get_path(&data.env, data.cmd1[0]);
	//printf("PATH = %s\n", data.path);
	/*if (data.path == NULL)
	{
		fprintf(stderr, "Command not foud : %s\n", data.cmd1[0]);
		return (1);
	}*/

	//char **exec = {&data.path, data.cmd1[0], data.cmd1[1]};
	//if (execve(data.path, exec, envp) == -1)
	//	perror("execve error");
	if (pipe(data.fd) == -1)
	{
		perror("Error : pipe");
		exit(EXIT_FAILURE);
	}
	data.pid = fork();
	if (data.pid == -1)
	{
		perror("Error : pid");
		exit(EXIT_FAILURE);
	}
	if (data.pid == 0)
	{
		//printf("PID of child process = %d\n", getpid());
		child_process(data, argv[2], envp);
	}
	else
	{
		//printf("PID of parent process = %d\n", getpid());
		parent_process(data, argv[3], envp);
	}
	return (0);
}
