/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:25:14 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/30 14:14:05 by nileempo         ###   ########.fr       */
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
		return (NULL);
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

	i = 0;
	if (cmd == NULL || cmd[0] == '\0')
	{
		write(2, "command not found\n", 18);
		exit(EXIT_FAILURE);
	}
	if (access(&cmd[0], F_OK | X_OK) == 0)
		return (&cmd[0]);
	check_cmds(&cmd);
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
void	check_path(char *path, char *cmds)
{
	if (path == NULL)
	{
		write(2, "command not found\n", 18);
		free(cmds);
		exit(EXIT_FAILURE);
	}
}

//check if the command start with /
void	check_cmds(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[0][i])
	{
		if (cmds[0][i] == '/')
		{
			write(2, "No such file or directory\n", 27);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
