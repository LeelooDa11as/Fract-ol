/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:36:58 by kkoval            #+#    #+#             */
/*   Updated: 2022/09/27 18:50:08 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst < src)
	{
		while (i < len)
		{
			d[i] = (unsigned char)s[i];
			i++;
		}
	}
	if (dst > src)
	{
		i = len;
		while (i != 0)
		{
			d[i - 1] = (unsigned char)s[i - 1];
			i--;
		}
	}
	return (dst);
}
/*
int main()
{
	char dst[100];
	ft_memmove((void *)dst, "hola", 3);

	printf("%s\n", dst);
	return(1);
}
*/
