/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:23:32 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 19:04:13 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			words++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static size_t	ft_word_len(char const *s, char c, size_t i)
{	
	size_t	len_s;

	len_s = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len_s++;
	}
	return (len_s);
}

static void	*ft_free(char**result, size_t x)
{	
	size_t	i;

	i = 0;
	while (i < x)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	x;
	size_t	word_num;

	i = 0;
	x = 0;
	word_num = ft_word_count(s, c);
	result = malloc(sizeof(char *) * (word_num + 1));
	if (!result)
		return (NULL);
	while (x < word_num)
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			result[x] = ft_substr(s, i, ft_word_len (s, c, i));
			if (!result[x])
				return (ft_free(result, x));
			x++;
		}
		i++;
	}
	result[x] = NULL;
	return (result);
}
/*
int	main(void)
{
	int i;
	char **resultado;
	char const	*s = " jfjfjf     ffhf       f     ";
	char		c = ' ';
	i = 0;
	
	resultado = ft_split(s, c);
	while(resultado[i])
	{
		printf("%s\n", resultado[i]);
	}
	return (1);
}*/
