/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:52:05 by nileempo          #+#    #+#             */
/*   Updated: 2022/11/09 10:46:43 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (0);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main ()
{
	char src[] = "test de la fonction";
	char dest[] = "123456789";
	printf("%s", ft_memcpy(dest, src, 5));
	printf("\n%s", memcpy(dest, src, 5));
	return (0);
}*/
