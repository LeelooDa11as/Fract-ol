/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:47:45 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/06 19:39:32 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Restrea los primeros n bytes del area de memoria apuntada por s buscando el
caracter c. La operacion acaba al llegar al imer byte que concuerda con c.
()

RETURN VALUES
devuelve un puntero al byte que concuerda, o NULL si el caracter no esta
en el area de memoria especificada.

*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c2;
	unsigned char	*s2;
	size_t			i;

	c2 = (unsigned char) c;
	s2 = (unsigned char *) s;
	i = 0;
	if (n <= 0)
		return (NULL);
	while (i < n)
	{
		if (s2[i] == c2)
		{
			return ((void *)&s2[i]);
		}
		i++;
	}
	if (i >= n)
		return (NULL);
	return (NULL);
}
/*
int	main(void)
{
	const void	*s = "jopl";
	int	c;
	size_t	n;

	c = 'p';
	n = 3;
	printf("%s\n", ft_memchr(s, c, n));
	return (1);
}*/
