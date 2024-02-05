/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:41:21 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/05 15:36:42 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	make_pipe_and_fork(t_p *data)
{
	if (pipe(data->fd) == -1)
		ft_errorexit("Pipe error");
	data->pid = fork();
	if (data->pid == -1)
		ft_errorexit("Fork error");
}

int	main(int argc, char **argv, char **envp)
{
	t_p		*data;
	char	**env;

	check_argc(argc);
	data = (t_p *)malloc(sizeof(t_p));
	if (!data)
		ft_errorexit("Memory allocation failed\n");
	init_struct(data);
	env = split_and_join_path(envp);
	data->infile_fd = check_infile(argv[1]);
	if (data->infile_fd == -1)
		ft_putstr_fd("No such file or directory\n", 2);
	else
		make_pipe_and_fork(data);
	if (data->pid == 0)
		child_process(data, env, argv);
	parent_process(data, env, argv);
	free_tab(env);
	free_path(data);
	free(data);
	return (0);
}
