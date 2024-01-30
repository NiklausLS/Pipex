/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:07:19 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/30 14:33:08 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//check the nbr of args
int	check_argc(int argc)
{
	if (argc != 5)
	{
		write(2, "Error : argument count is wrong.\n", 33);
		exit(EXIT_FAILURE);
	}
	return (0);
}

//check if the file exist and can be read
int	check_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "infile: No such file or directory\n", 35);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

//check if outfile exit. If he don't, make one
int	check_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		write(2, "Error : open outfile\n", 21);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

//check if the command is a directory
void	check_if_dir(char *cmd)
{
	int	dir;

	dir = open(cmd, O_DIRECTORY);
	if (dir != -1)
	{
		close (dir);
		write(2, "No such file or directory\n", 27);
		exit(EXIT_FAILURE);
	}
}
