/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacarazohidalgo <mariacarazohidalgo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:27:52 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/09/25 21:29:43 by mariacarazo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include

void	ft_putendl_fd(char *s, int fd)
{
	if (s != 0)
	{
		write(fd, s, ft_strlen(s));
		write(1, "\n", 1); // no se que comillas
	}
}