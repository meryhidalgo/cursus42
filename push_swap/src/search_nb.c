/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:06:12 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/02 13:01:20 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Estas funciones buscan el menor número del stack arriba y abajo y devuelven 
su posición. Tal vez se podría mejorar dando como entrada tanto el chunk como 
mult y que j empiece directamente en (chunk * (mult - 1))*/
int	upwards(int *tab, int *sorted, int range[2], int length)
{
	int	i;
	int	j;

	i = 0;
	if (range[1] > (range[0] - 3))
		range[1] = range[0] - 3;
	while (i < length)
	{
		j = 0;
		while (j < (range[1]))
		{
			if (tab[i] == sorted[j++])
				return (i);
		}
		i++;
	}
	return (-1);
}

int	downwards(int *tab, int *sorted, int range[2], int length)
{
	int	i;
	int	j;

	i = length - 1;
	if (range[1] > (range[0] - 3))
		range[1] = range[0] - 3;
	while (i >= 0)
	{
		j = 0;
		while (j < (range[1]))
		{
			if (tab[i] == sorted[j++])
				return (i);
		}
		i--;
	}
	return (-1);
}
