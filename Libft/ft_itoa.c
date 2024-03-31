/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:59:17 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 18:35:52 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Utilizando malloc(3), genera una string que represente el valor entero 
 * recibido 
como argumento. Los números negativos tienen que gestionarse. */

#include "libft.h"

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_abs_val(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

char	*ft_itoa(int a)
{
	char	*result;
	int		i;

	if (a == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_num_len(a);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	if (a < 0)
		result[0] = '-';
	a = ft_abs_val(a);
	result[i] = '\0';
	if (a == 0)
		result[0] = '0';
	while (a > 0)
	{
		i--;
		result[i] = a % 10 + '0';
		a = a / 10;
	}
	return (result);
}
/*
int	main(void)
{
	int	a;

	a = -214;
	printf("%s", ft_itoa(a));
	return (1);
}*/
