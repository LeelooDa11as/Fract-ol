/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:39:53 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/10 14:50:17 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{	
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)s;
	while (len >= 0)
	{
		if (str[len] == (char)c)
		{
			return (&str[len]);
		}
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*s = "ex nihilo";
	int	c;
	char	*x;

//	x = ft_strrchr(s);
	c = 'Z';
	x = ft_strrchr(s, c);
	//printf("Lo que me devuelve la funcion apunta a %s\n", ft_strrchr(s,c));
	printf("En la X apuntamos ha %s\n", x);	

	return (1);
}*/
