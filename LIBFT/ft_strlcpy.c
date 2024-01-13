/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:26:13 by nileempo          #+#    #+#             */
/*   Updated: 2022/11/21 10:00:18 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(src);
	if (!src)
		return (0);
	if (size == 0)
		return (count);
	while (src[i] && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
/*
int main()
{
	char dst[42] = "Test";
	char dst2[42] = "Test";
	char src[42] = "";
	size_t size = 10;
	printf("dst avant : %s\n", dst);
	printf("Vraie fonction : %lu\n", strlcpy(dst2, src, size));
	printf("Ma fonction : %lu\n", ft_strlcpy(dst, src, size));
	printf("Ma dst apres : %s\n", dst);
	printf("Vraie dst apres : %s", dst2);
	return (0);
}*/
