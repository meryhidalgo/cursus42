/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:58:11 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/23 12:29:20 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

int	nb_digit(int n)
{
	int	i;

	if (n < 0)
		i = 2;
	else
		i = 1;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	char	j;

	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	j = nb % 10 + 48;
	write (1, &j, 1);
}

int	check(int i, int j, t_map *map)
{
	if (map->matrix[i][j] == '1')
		return (1);
	else if (map->matrix[i][j] == 'C')
	{
		map->elements[0]--;
		map->matrix[i][j] = '0';
	}
	else if (map->matrix[i][j] == 'E' && map->elements[0] == 0)
		return (2);
	else if (map->matrix[i][j] == 'E' && map->elements[0] != 0)
		return (3);
	return (0);
}

int	move_up_down(int keysym, t_map *map)
{
	int	ch;

	if (keysym == 125 || keysym == 1)
	{
		ch = check(map->player[0] + 1, map->player[1], map);
		if (ch == 1)
			return (1);
		map->player[0]++;
	}
	else
	{
		ch = check(map->player[0] - 1, map->player[1], map);
		if (ch == 1)
			return (1);
		map->player[0]--;
	}
	return (ch);
}

int	move_player(int keysym, t_map *map)
{
	int	ch;

	if (keysym == 123 || keysym == 0)
	{
		ch = check(map->player[0], map->player[1] - 1, map);
		if (ch == 1)
			return (1);
		map->player[1]--;
	}
	else if (keysym == 124 || keysym == 2)
	{
		ch = check(map->player[0], map->player[1] + 1, map);
		if (ch == 1)
			return (1);
		map->player[1]++;
	}
	else
		ch = move_up_down(keysym, map);
	return (ch);
}
