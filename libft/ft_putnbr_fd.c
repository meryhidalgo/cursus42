/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacarazohidalgo <mariacarazohidalgo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:29:53 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/09/25 21:33:00 by mariacarazo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include

void	ft_putnbr_fd(int nb, int fd) // gestion de negativos ?
{
	char	j;

	if (nb == -2147483648)
		write (fd, "-2147483648", 11);
	else if (nb < 0)
	{
		write (fd, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
	   if (nb/10 != 0)
			ft_putnbr(nb/10);
		j = nb % 10 + 48;
		write (fd, &j, 1);
	}
}