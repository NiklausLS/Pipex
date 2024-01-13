/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:03:10 by nileempo          #+#    #+#             */
/*   Updated: 2022/12/01 10:47:26 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t ecount, size_t esize)
{
	void	*ptr;

	ptr = malloc(ecount * esize);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, ecount * esize);
	return (ptr);
}

/*
int	main()
{
	char *ptr;
	char *p;

	ptr = calloc(20, sizeof(int));
	p = ft_calloc(20, sizeof(int));
	printf("Vraie fonction : ");
	if (ptr == NULL)
		printf("Allocation impossible\n");
	else
		printf("Allocation OK\n\n");
	printf("Ma fonction : ");
	if (p == NULL)
		printf("Allocation impossible");
	else
		printf("Allocation OK");
	printf("%s", p);
	return (0);
}*/
