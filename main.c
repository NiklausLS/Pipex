/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:41:21 by nileempo          #+#    #+#             */
/*   Updated: 2023/08/15 15:55:04 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//check argc
//check open file

int main(int argc, char **argv)
{
	t_p file;

	check_argc(argc);
	file.infile = check_open(argv[1], O_RDONLY);
    	file.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDONLY, 0000644);
	if (file.outfile == -1)
		perror("Error : Open function returned -1\n"); 
	
		
	printf("argc = %d\n", argc);
	printf("argv[0] = %s\n", argv[0]);
	printf("fd = %d\n", file.infile);
	return (0);
}
