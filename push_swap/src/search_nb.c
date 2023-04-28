/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:06:12 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/28 20:06:19 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	upwards(int *tab, int *sorted, int num, int length)
{
	int	i;
	int	j;

	i = 0;
	//if (num >= length)
	//	num = num - 3;
	while (i < length)
	{
		j = 0; //poco eficiente
		while (j < (num)) //eh
		{
			if (tab[i] == sorted[j++])
				return (i);
		}
		i++;
	}
	return (-1);
}

int	downwards(int *tab, int *sorted, int num, int length)
{
	int	i;
	int	j;

	i = length;
	//if (num >= length)
	//	num = num - 3;
	while (i >= 0)
	{
		j = 0; //poco eficiente
		while (j < (num)) //eh
		{
			if (tab[i] == sorted[j++])
				return (i);
		}
		i--;
	}
	return (-1);
}
