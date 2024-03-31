/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:28:12 by kkoval            #+#    #+#             */
/*   Updated: 2023/03/09 18:51:00 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	s: La string a enviar. 
	fd: El file descriptor sobre el que escribir.
	Envía la string ’s’ al file descriptor dado, seguido de un salto de linea.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = (int) ft_strlen(s);
	while (i < len)
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
	return ;
}
/*
int	main(void)
{
	char	*s= "heyhey";
	int		fd;

	fd = 1;
	ft_putendl_fd(s, fd);
	return (1);
}*/
