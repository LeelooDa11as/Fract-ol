/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:47:09 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/10 15:06:32 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		x = 0;
		while (haystack[i + x] == needle[x] && needle[x] != '\0'
			&& (x + i) < len)
			x++;
		if (needle[x] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*haystack = "Cafe con leche";
	const char	*needle = "con";
	size_t	len;

	len = 10;
	printf("%s\n", ft_strnstr(haystack, needle, len));
	return (1);
}*/
