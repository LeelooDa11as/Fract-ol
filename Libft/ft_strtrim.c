/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:47:38 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 18:09:37 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_inside_the_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	x;
	size_t	end;
	char	*new;

	start = 0;
	end = ft_strlen(s1);
	if (end != 0)
		end--;
	while (s1[start] != '\0' && char_is_inside_the_set(s1[start], set))
		start++;
	while (end > start && char_is_inside_the_set(s1[end], set))
		end--;
	if (end - start == 0 && start == 0 && s1[0] == '\0')
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!new)
		return (NULL);
	x = 0;
	while (start <= end)
		new[x++] = s1[start++];
	new[x] = '\0';
	return (new);
}

/*
int main(void)
{
	printf("%s\n", ft_strtrim("z", "acb"));
}*/
