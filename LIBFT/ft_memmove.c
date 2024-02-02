/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:48:04 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/02 15:33:58 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	if (s < d)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (n > i)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*int main()
{
	char s[] = "TEST";
	char s2[] = "TEST";
	char cpy[] = "TEST";

	char d[50] = "123456789";

	printf("memcpy : %s\n", memcpy(d + 1, cpy, 10));
	printf("Ma fonction : %s\n", ft_memmove(d + 1, s, 10));
	printf("autre : %s", memmove(d + 1, s2, 10));
}*/
