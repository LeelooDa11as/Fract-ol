/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:48:01 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 18:47:05 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	s: La string a enviar.
	fd: El file descriptor sobre el que escribir.
	Envía la string ’s’ al file descriptor especificado.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{	
	int	i;
	int	len;

	i = 0;
	len = (int) ft_strlen(s);
	while (i < len)
	{
		write(fd, s + i, 1);
		i++;
	}
	return ;
}
/*
int	main(void)
{
	char	*s = "Nina";
	int		fd;

	fd = 1;
	ft_putstr_fd(s, fd);
	return (1);
}*/
