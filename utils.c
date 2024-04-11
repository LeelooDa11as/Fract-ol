/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:30:52 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/10 17:46:14 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check_input(char *str)
{
	int	point;

	point = 0;
	if (*str == '\0')
		return (0);
	while(*str != '\0')
	{
		if (ft_isalpha(*str) == 1)
			return (0);
		if (*str == '.')
			point += 1;
		if (point > 1)
			return (0);
		str++;
	}
	return (1);
}

double	ft_atof(char *str)
{
	double	res;
	double	sign;
	int		div;

	res = 0;
	sign = 1;
	div = 1;
	while (ft_ispace(*str) && *str != '\0')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && ((*str >= '0' && *str <= '9') || *str == '.'))
	{
		if (*str >= '0' && *str <= '9')
		{
			res = res * 10 + *str - '0';
			div *= 10;
		}
		str++;
	}
	res = res / (div / 10);
	res = res * sign;
	return (res);
}

int	ft_ispace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\f')
		return (1);
	return (0);
}
