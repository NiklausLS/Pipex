/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:36:49 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/29 01:15:14 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*static void free_cmd(char **cmd)
{
    int i;

    i = 0;
    while (cmd[i])
    {
        free(cmd[i]);
        i++;
    }
    free(cmd);
}*/

void    init_cmds(char **argv, t_p *data)
{
    data->cmd1 = ft_split(argv[2], ' ');
    data->cmd2 = ft_split(argv[3], ' ');
}
