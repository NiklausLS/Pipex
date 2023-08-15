/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:07:19 by nileempo          #+#    #+#             */
/*   Updated: 2023/08/15 15:42:26 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//to do list
//check the nbr of args
//check open the file

//check the number of arguments
int	check_argc(int argc)
{
    if (argc != 5)
    {
        perror("Error : argument count is wrong.\n");
        exit(EXIT_FAILURE);
    }
    return (0);
}

//check the opening of the file
int	check_open(char *file, int flags)
{
    int fd;

    fd = open(file, flags);
    if (fd == -1)
    {
        perror("Error : Open function returned -1.\n");
        exit(EXIT_FAILURE);
    }
    return (fd);
}
