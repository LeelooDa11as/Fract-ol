/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:04:21 by kkoval            #+#    #+#             */
/*   Updated: 2022/11/13 18:35:37 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros 
 el índice de cada carácter dentro de ’s’ y la dirección del propio carácter,
 que podrá modificarse si es necesario. */
/*
void	*f(unsigned int i, char *s)
{
	void	*f;

	f = s[i];
	return (f);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/*
int	main(void)
{
	char	*s = "yey yey";

	printf("%s", ft_striteri(s));
	return (1);
}
//PASO POR VALOR
//aqui la a de f, es una copia de a, y por lo tanto no modifica la a original
a = 3;
f(a);
void f(int patata)
{
	patata++;
}
PASO POR REFERENCIA la a de f, es una referencia a la a original, por lo tanto
si modifica la original
a =3
f(&a);
void f(int *patata)
{
	patata++;
}
*/
