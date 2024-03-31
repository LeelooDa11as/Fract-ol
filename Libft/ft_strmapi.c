/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:17:18 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 18:38:03 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* A cada carácter de la string ’s’, aplica la
función ’f’ dando como parámetros el índice de cada carácter dentro de ’s’ y 
el propio carácter. Genera una nueva string con el resultado del uso sucesivo 
de ’f’ */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	printf("%s", ft_strmapi("mpm", f));
}*/
