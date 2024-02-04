/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:59:03 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/04 21:59:06 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(t_p *data)
{
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->pid = -1;
	data->path1 = NULL;
	data->path2 = NULL;
}

void	free_cmd1(t_p *data)
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
	}
}

void	free_cmd2(t_p *data)
{
	int	i;

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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_path(t_p *data)
{
	if (data->path1 != NULL)
		free(data->path1);
	if (data->path2 != NULL)
		free(data->path2);
}
