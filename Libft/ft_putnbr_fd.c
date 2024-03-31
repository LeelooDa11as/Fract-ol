/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:05:40 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 18:56:50 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write (fd, "-2147483648", 11);
			return ;
		}
		else
		{	
			n *= -1;
			ft_putchar('-', fd);
		}
	}
	if (n <= 9)
		ft_putchar(n + '0', fd);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar(n % 10 + '0', fd);
	}
	return ;
}
/*
int	main(void)
{
	int	n;
	int	fd;

	n = 987441;
	fd = 1;
	ft_putnbr_fd(n, fd);
	return (1);
}*/
