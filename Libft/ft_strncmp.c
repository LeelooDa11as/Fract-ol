/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:28:12 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/10 14:43:00 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while (ptr1[i] != '\0' && ptr2[i] != '\0' && i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	if (i < n && (ptr1[i] == '\0' || ptr2[i] == '\0'))
		return (ptr1[i] - ptr2[i]);
	return (0);
}
/*
int	main(void)
{
	const char	*s1 = "1234";
	const char	*s2 = "1235";
	size_t	n;

	n = 4;
	printf("Mi ft =%d", ft_strncmp(s1, s2, n));
	return (1);
}*/
