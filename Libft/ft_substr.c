/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:27:07 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 17:35:32 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_comp(char *sub)
{
	sub = malloc(sizeof(char) * 1);
	if (!sub)
		return (NULL);
	sub[0] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	lenght_s;

	sub = NULL;
	i = 0;
	lenght_s = ft_strlen(s);
	if (start + len < lenght_s)
		sub = malloc(sizeof(char) * (len + 1));
	else if (start > lenght_s)
		return (ft_comp(sub));
	else
		sub = malloc(sizeof(char) * (lenght_s - start + 1));
	if (!sub)
		return (NULL);
	while (s[start + i] != '\0' && start < lenght_s && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char const	*s = "I just want this part ###########";
	unsigned int	start;
	size_t	len;

	start = 5;
	len = 10;
	printf("%s\n", ft_substr(s, start, len));
	return (1);
}*/
