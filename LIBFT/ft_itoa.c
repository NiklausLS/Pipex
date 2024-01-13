/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:56:06 by nileempo          #+#    #+#             */
/*   Updated: 2022/12/01 09:25:43 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static int	ft_len(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		size++;
	}
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	long	nb;

	nb = n;
	size = ft_len(n);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
		nb = nb * -1;
	str[size] = 0;
	while (size--)
	{
		str[size] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
int main()
{
	int n = 0;
	int neg = -999999;

	printf("%s et ", ft_itoa(n));
	printf("%s", ft_itoa(neg));
	return (0);
}*/
