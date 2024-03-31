/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:53:32 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 17:17:00 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dub;
	size_t	i;

	i = 0;
	dub = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dub)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		dub[i] = s1[i];
		i++;
	}
	dub[i] = '\0';
	return (dub);
}
/*
int	main(void)
{
	const char	*s1 = "ya programuyu, lol";

	printf("%s\n", ft_strdup(s1));
	return (1);
}*/
