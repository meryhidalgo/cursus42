/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:29:53 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/10/24 19:53:14 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long nb, int fd)
{
	char	j;

	if (nb == -2147483648)
		write (fd, "-2147483648", 11);
	else if (nb < 0)
	{
		write (fd, "-", 1);
		ft_putnbr_fd(-nb, fd);
	}
	else
	{
		if (nb / 10 != 0)
			ft_putnbr_fd(nb / 10, fd);
		j = nb % 10 + 48;
		write (fd, &j, 1);
	}
}
