/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:52 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/02 15:33:37 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	target;

	i = 0;
	str = (unsigned char *) s;
	target = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == target)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*int main()
{
	char s[] = "test de la fonction";
	printf("Vraie fonction : %s\n", memchr(s, 'a', 20));
	printf("Ma fonction : %s", ft_memchr(s, 'a', 20));
}*/
