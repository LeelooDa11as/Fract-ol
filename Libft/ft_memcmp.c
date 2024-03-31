/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:50:25 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/10 14:53:37 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	if (st1 == NULL && st2 == NULL )
		return (0);
	if (n <= 0)
		return (0);
	while (i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const void	*s1 = "";
	const void	*s2 = "";
	size_t	n;

	n = 0;
	printf("%d", ft_memcmp(s1, s2, n));
	return (1);
}*/
