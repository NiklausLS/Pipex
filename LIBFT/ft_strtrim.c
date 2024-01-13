/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:21:55 by nileempo          #+#    #+#             */
/*   Updated: 2024/01/09 13:23:47 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (s1 && ft_strchr(set, s1[start]))
		s1++;
	return ((char *)s1);
}
/*
int main()
{
	char *s1 = "_\n\ttest de la fonction_\n\t";
	char *s2 = "123test de la fonction123";

	char *trim1 = "_\n\t";
	char *trim2 = "123";

	printf("s1 : %s\n", ft_strtrim(s1, trim1));
	printf("s2 : %s\n", ft_strtrim(s2, trim2));
	return (0);
}*/
