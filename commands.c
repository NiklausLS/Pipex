/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:36:49 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/30 15:59:14 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(char **argv, t_p *data)
{
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	data->infile_fd = check_infile(argv[1]);
	data->outfile_fd = check_outfile(argv[4]);
}

void	free_cmds(t_p *data)
{
	int	i;

	i = 0;
	if (data->cmd1 != NULL)
	{
		while (data->cmd1[i])
		{
			free(data->cmd1[i]);
			i++;
		}
		free(data->cmd1);
		data->cmd1 = NULL;
	}
	i = 0;
	if (data->cmd2 != NULL)
	{
		while (data->cmd2[i])
		{
			free(data->cmd2[i]);
			i++;
		}
		free(data->cmd2);
		data->cmd2 = NULL;
	}
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	if (env != NULL)
	{
		while (env[i])
		{
			free(env[i]);
			i++;
		}
		free(env);
	}
}

void	free_path(t_p *data)
{
	if (data->path1 != NULL)
		free(data->path1);
	if (data->path2 != NULL)
		free(data->path2);
}
