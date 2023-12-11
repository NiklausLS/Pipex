/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:41:21 by nileempo          #+#    #+#             */
/*   Updated: 2023/12/11 13:21:02 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//check argc
//check open file

int main(int argc, char **argv)
{
	t_p		file;
	
	check_argc(argc);
	check_file(argv[1]);
	check_file(argv[4]);
	file.file1_fd = check_open(argv[1], O_RDWR);
	file.file2_fd = check_open(argv[4], O_RDWR);
	if (pipe(file.fd == -1))
		exit(EXIT_FAILURE);
	file.pid = fork();
	if (file.pid == -1)
		exit(EXIT_FAILURE);
	//printf("argc = %d\n", argc);
	//printf("argv[0] = %s\n", argv[0]);
	printf("fd = %d\n", file.file1_fd);
	printf("fd = %d\n", file.file2_fd);
	if (file.pid == 0)
		printf("PID processus enfant = %d\n", getpid());
	else
		printf("PID processus parent = %d / PID processus enfant = %d\n", getpid(), file.pid);
		dup2(file.file1_fd, 1);
		dup2(file.fd[0], 0);
	return (0);
}
