/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:25:14 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/05 00:17:43 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//get path from envp and return a path to it
static char	*get_env(char **envp)
{
	char	*path;

	if (envp == NULL || *envp == NULL)
		return (NULL);
	while (*envp != NULL && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (*envp == NULL)
		return (NULL);
	path = *envp + 5;
	if (path == NULL)
		return (NULL);
	return (path);
}

//split the result and add / at the end
char	**split_and_join_path(char **envp)
{
	char	*path;
	char	*tmp;
	int		i;
	char	**env;

	path = get_env(envp);
	if (path == NULL)
		return (NULL);
	env = ft_split(path, ':');
	if (env == NULL || *env == NULL)
		return (NULL);
	i = 0;
	while (env[i])
	{
		tmp = env[i];
		env[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}
	return (env);
}

//check env_path to find cmd repertory
//use access to check if file exist and is accessible
char	*get_path(char *cmd, char **env)
{
	char	*path;
	int		i;

	i = 0;
	if (cmd == NULL || cmd[0] == '\0')
		ft_errorexit("command not found\n");
	check_if_dir(cmd);
	if (access(&cmd[0], F_OK | X_OK) == 0)
		return (&cmd[0]);
	check_cmd(cmd);
	if (env == NULL || env[0] == NULL)
		ft_errorexit("command not found\n");
	while (env[i])
	{
		path = ft_strjoin(env[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

//check if the command get a /
void	check_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			free(cmd);
			ft_errorexit("No such file or directory\n");
		}
		i++;
	}
}

int	if_no_path(char **env, char *cmd)
{
	if (!env || !*env)
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (0);
	}
	return (-1);
}
