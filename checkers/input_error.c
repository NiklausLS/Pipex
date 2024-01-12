/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:07:19 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/09 16:25:07 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//check the nbr of args
int	check_argc(int argc)
{
	if (argc != 5)
	{
		perror("Error : argument count is wrong.\n");
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
		perror("Error : infile.\n");
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
		perror("Error : outfile");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
