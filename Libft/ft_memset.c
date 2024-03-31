/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:05:36 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/10 14:44:39 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = b;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char	str[] = "holaquetal";
	int	c;
	size_t	len;

	c = 'k';
	len = 3;
	printf("%s\n", str);

	printf(">>>%s<<<\n", ft_memset(str, c, len));
	return (1);
}*/
