/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:51:05 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/10 14:31:49 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*s;
	size_t	src_len;

	i = 0;
	s = (char *) src;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 1)
	{
		dst[i] = '\0';
		return (src_len);
	}
	if (dstsize >= 2)
	{
		while (s[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = s[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
int	 main(void)
{
	char	*dst;
	//const char	*src = "im";
	size_t	dstsize;

	dstsize  = 8;
	printf("%zu", ft_strlcpy(dst, "aaa", 2));
	printf("%s\n", dst);
	return (1);
}*/
