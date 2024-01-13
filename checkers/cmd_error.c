/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:25:14 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/13 02:42:00 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//to do list
//get envp path

//get path from **envp by checking 5 first char 
//split the result and add / at the end
char	**get_env_path(char **envp)
{
	char	*path;
	char	*tmp;
	int		i;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	path = *envp + 5;
	envp = ft_split(path, ':');
	i = 0;
	//puts("get env path");
	while (envp[i])
	{
		tmp = ft_strjoin(envp[i], "/");
		envp[i] = tmp;
		//printf("envp[%d] = %s\n", i, envp[i]);
		i++;
	}
	return (envp);
}

//split the cmd
/*
char	**get_cmd(char *cmd)
{
	char	**cmds;
	int		i;

	cmds = ft_split(cmd, ' ');
	i = 0;
	while (cmds[i])
	{
		//printf("cmd[%d] = %s\n", i, cmds[i]);
		i++;
	}
	return (cmds);
}*/

//check env_path to fond cmd repertory
//use access to check if file exist and is accessible and return 0 if it's ok
char	*get_path(char *cmd, char **envp)
{
	char	*path;
	int		i;

	i = 0;
	//puts("get_path");
	while (envp[i])
	{
		//printf("envp[%d] =  %s\n", i, envp[i]);
		path = ft_strjoin(envp[i], cmd);
		if (access(path, F_OK) == 0)
			return (path);
		else
			free(path);
		i++;
	}
	return (NULL);
}