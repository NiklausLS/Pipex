/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:25:14 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/26 18:17:15 by nileempo         ###   ########.fr       */
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

	if (envp == NULL || envp[0] == NULL)
		exit (EXIT_FAILURE);
	while (*envp != NULL && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (*envp == NULL)
		return (NULL);
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
	if (access(cmds[0], F_OK | X_OK) == 0)
		return (cmds[0]);
	if (envp == NULL || envp[0] == NULL)
		return (NULL);
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

//check if the path exist
int	*check_path(char *path, char **cmds)
{
	if (path == NULL)
	{
		write(2, "Command not found\n", 18);
		free(cmds);
		exit(EXIT_FAILURE);
	}
	return (0);
}

//check if the command is not empty and if it's not starting with /
int		*check_cmds(char *path, char **cmds)
{
	if (cmds[0] == NULL)
		exit(EXIT_FAILURE);
	if (ft_strncmp(cmds[0], path, ft_strlen(path)) != 0)
	{
		write(2, "Command not found\n", 18);
		free(cmds);
		exit(EXIT_FAILURE);
	}
	return (0);
}