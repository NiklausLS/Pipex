/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:36:06 by nileempo          #+#    #+#             */
/*   Updated: 2022/11/21 15:01:14 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main()
{
	char *s = "test";
	char *s2 = "test";
	char *t = "";
	char *t2 = "";
	printf("before : %s\n", t);
	t = strdup(s);
	printf("after : %s \n", t);

	printf("before : %s\n", t2);
	t2 = ft_strdup(s2);
	printf("after : %s", t2);
	return (0);
}*/
