/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:06:09 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 18:03:43 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	count;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	count = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (size_s1 + size_s2 +1));
	if (ptr == NULL)
		return (NULL);
	while (count < size_s1)
	{
		ptr[count] = s1[count];
		count++;
	}
	count = 0;
	while (count++ < size_s2)
		ptr[size_s1 + count - 1] = s2[count - 1];
	ptr[size_s1 + count - 1] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char const	*s1 = "Hey you";
	char const	*s2 = " how are you?";
	
	printf("%s", ft_strjoin(s1, s2));
	return (1);
}*/
