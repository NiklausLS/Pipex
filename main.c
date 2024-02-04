/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:41:21 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/05 00:27:17 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (pipe(data->fd) == -1)
		ft_errorexit("Pipe failed\n");
	data->pid = fork();
	if (data->pid == -1)
		ft_errorexit("Pid failed\n");
	if (data->pid == 0)
		child_process(data, env, argv);
	else
		parent_process(data, env, argv);
	free_tab(env);
	free_path(data);
	free(data);
	return (0);
}
