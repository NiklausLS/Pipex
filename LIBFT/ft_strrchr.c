/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:25:44 by nileempo          #+#    #+#             */
/*   Updated: 2022/11/16 09:51:11 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s);
	ptr = (char *)s;
	if (c == '\0')
		return (ptr + ft_strlen(s));
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (ptr + i);
		i--;
	}
	return (0);
}
/*
int main()
{
	char *s = "abcdefghijklmnopqrstuvwxyz";
	int c = 't';

	printf("Vraie fonction : %s\n", strrchr(s, c));
	printf("Ma fonction : %s", ft_strrchr(s, c));
	return (0);
}*/
