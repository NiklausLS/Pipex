/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:41:21 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/19 16:12:45 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_p		data;
	char	**env;

	check_argc(argc);
	data.infile_fd = check_infile(argv[1]);
	data.outfile_fd = check_outfile(argv[4]);
	env = get_env_path(envp);
	if (pipe(data.fd) == -1)
	{
		write(2, "Error : pipe\n", 13);
		exit(EXIT_FAILURE);
	}
	data.pid = fork();
	if (data.pid == -1)
	{
		write(2, "Error : pid\n", 12);
		exit(EXIT_FAILURE);
	}
	if (data.pid == 0)
		child_process(data, argv[2], env);
	else
		parent_process(data, argv[3], env);
	return (0);
}
