/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:08:00 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/06 19:46:46 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *) src;
	d = (char *) dst;
	if (s == NULL && d == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)d);
}
/*
int	main()
{
	void	*dst;
	const void	*src;
	size_t	n;

	n = 7;
	printf("%s\n", ft_memcpy(((void *)0), ((void *)0), 3));
	return (1);
}*/
