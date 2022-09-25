/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacarazohidalgo <mariacarazohidalgo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:25:33 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/09/25 21:27:38 by mariacarazo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
		write(fd, s, ft_strlen(s)); // s ya es la dirección, no hace falta &s
}