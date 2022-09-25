/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacarazohidalgo <mariacarazohidalgo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:22:29 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/09/25 21:24:02 by mariacarazo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	//puntero s vacio?
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}