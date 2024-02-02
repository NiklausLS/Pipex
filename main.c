/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:41:21 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/02 15:29:33 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_p		data;
	char	**env;

	check_argc(argc);
	env = get_env_path(envp);
	if (pipe(data.fd) == -1)
		ft_errorexit("Error : pipe\n");
	data.pid = fork();
	if (data.pid == -1)
		ft_errorexit("Error : pid\n");
	if (data.pid == 0)
		child_process(data, env, argv);
	waitpid(data.pid, NULL, 0);
	parent_process(data, env, argv);
	return (0);
}
