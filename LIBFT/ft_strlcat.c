/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:43:25 by nileempo          #+#    #+#             */
/*   Updated: 2022/11/21 14:35:56 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	if ((!dst || !src) && size == 0)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && (i + dst_len) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int main()
{
	char dst[42] = "";
	char dst2[42] = "";
	char *src = "123";
	size_t size = 0;

	printf("La fonction renvoie : %lu\n", strlcat(dst, src, size));
	printf("Ma fonction renvoie : %lu\n", ft_strlcat(dst2, src, size));
	printf("DST =  %s\n", dst);
	printf("DST2 = %s", dst2);
	return (0);
}*/
