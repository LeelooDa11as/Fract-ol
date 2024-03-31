/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:17 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/10 14:48:00 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	dst_length(char *dst)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0')
		i++;
	return (i);
}

static size_t	src_length(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dst_len = dst_length(dst);
	src_len = src_length(src);
	if (!(dstsize == 0) || !(dst_len >= dstsize))
	{
		while (dst[i] != '\0')
			i++;
		while ((src[j] != '\0') && ((i + j) < (dstsize - 1)))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	return (dst_len + src_len);
}
