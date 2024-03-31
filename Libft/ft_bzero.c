/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:30:50 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 17:00:30 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*src;

	src = s;
	i = 0;
	while (i < n)
	{
		src[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	s[100];
	//void *s2;

	//s2 = (void *)s;
	size_t	n;

	n = 3;
	printf("%s", ft_bzero(s, n);
	return (1);
}*/
