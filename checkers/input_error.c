/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:07:19 by nileempo          #+#    #+#             */
/*   Updated: 2023/12/05 16:52:15 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//to do list
//check the nbr of args
//check open the file

int	check_argc(int argc)
{
    if (argc != 5)
    {
        perror("Error : argument count is wrong.\n");
        exit(EXIT_FAILURE);
    }
    return (0);
}

//check if the file exist and can be readed
int check_file(char *file)
{
    if (access(file, F_OK) == -1)
    {
        perror("The file doesn't exist\n");
        exit(EXIT_FAILURE);
    }
    else if (access(file, R_OK) == -1)
    {
        perror("The file can't be read");
        exit(EXIT_FAILURE);
    }
    return (0);
}

//Open the file and check if i can read and write in it
int	check_open(char *file, int flag)
{
    int fd;

    fd = open(file, flag);
    if (fd == -1)
    {
        perror("Error : Open function returned -1.\n");
        exit(EXIT_FAILURE);
    }
    return (fd);
}
