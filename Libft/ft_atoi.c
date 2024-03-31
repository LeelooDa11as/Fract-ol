/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:12:09 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 18:28:31 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ispace(char c)
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

int	ft_atoi(const char *str)
{
	int	res;
	int	sig;

	res = 0;
	sig = 1;
	while (ft_ispace(*str))
		str++;
	if (*str == '-')
		sig = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sig);
}
/*
int	main(void)
{
	const char str[] = "42 Barcelona";

//	str = "h+-5698kkk";
	printf("%d", ft_atoi(str));
	return (1);
}*/
