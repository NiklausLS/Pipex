/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:25:14 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/13 16:22:31 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
void	*check_cmd(char *cmd)
{
	char	**check;

	check = ft_split(cmd, ' ');
	if (cmd[0] == NULL)
		exit(EXIT_FAILURE);
	free(check);
}*/

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
	while (envp[i])
	{
		tmp = ft_strjoin(envp[i], "/");
		envp[i] = tmp;
		i++;
	}
	return (envp);
}

//check env_path to find cmd repertory
//use access to check if file exist and is accessible
char	*get_path(char *cmd, char **envp)
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		path = ft_strjoin(envp[i], cmd);
		if (access(path, F_OK) == 0)
			return (path);
		else
			free(path);
		i++;
	}
	return (NULL);
}
