/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:25:14 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/18 00:02:23 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//get path from **envp by checking 5 first char 
//split the result and add / at the end
char	**get_env_path(char **envp)
{
	char	*path;
	char	*tmp;
	int		i;
	char	**env;

	if (!envp)
		return (NULL);
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	path = *envp + 5;
	env = ft_split(path, ':');
	i = 0;
	while (env[i])
	{
		tmp = env[i];
		env[i] = ft_strjoin(env[i], "/");
		free(tmp);
		i++;
	}
	return (env);
}

//check env_path to find cmd repertory
//use access to check if file exist and is accessible
char	*get_path(char *cmd, char **envp)
{
	char	*path;
	int		i;
	char	**cmds;

	i = 0;
	cmds = ft_split(cmd, ' ');
	if(access(cmds[0], F_OK | X_OK) == 0)
		return(cmds[0]);
	while (envp[i])
	{
		path = ft_strjoin(envp[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
/*
char	get_cmd(char *cmd)
{
	if (acces(cmd, F_OK | X_OK) == O)

}*/