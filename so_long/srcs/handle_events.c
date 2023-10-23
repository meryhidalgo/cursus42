/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:05:09 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/23 13:28:05 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

/*void	leaks(void)
{
	system("leaks -q so_long");
}*/

int	end_game(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.row)
		free (data->map.matrix[i++]);
	free(data->map.matrix);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	free(data->win_ptr);
	free(data->mlx_ptr);
	exit (0);
	return (0);
}

void	black_and_pac(t_data data, t_map *map, int x[2], int keysym)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.black.img,
		D_SIZE * map->player[1], D_SIZE * map->player[0]);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.black.img,
		D_SIZE * x[0], D_SIZE * x[1]);
	if (keysym == 123 || keysym == 0)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.pacR.img,
			D_SIZE * map->player[1], D_SIZE * map->player[0]);
	else if (keysym == 124 || keysym == 1)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.pacL.img,
			D_SIZE * map->player[1], D_SIZE * map->player[0]);
	else if (keysym == 125 || keysym == 2)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.pacD.img,
			D_SIZE * map->player[1], D_SIZE * map->player[0]);
	else
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.pacU.img,
			D_SIZE * map->player[1], D_SIZE * map->player[0]);
}

int	repaint(t_data data, t_map *map, int keysym)
{
	int	x[2];
	int	ch;

	x[0] = map->player[1];
	x[1] = map->player[0];
	ch = move_player(keysym, map);
	if (ch == 1)
		return (1);
	else if (ch == 3)
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.black.img,
			D_SIZE * x[0], D_SIZE * x[1]);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.pacL.img,
			D_SIZE * map->player[1], D_SIZE * map->player[0]);
	}
	else
		black_and_pac(data, map, x, keysym);
	if (map->matrix[x[1]][x[0]] == 'E' && map->elements[0] != 0)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.exit.img,
			D_SIZE * x[0], D_SIZE * x[1]);
	if (ch == 2)
		return (2);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	int		value;

	if (keysym == XK_ESC)
		end_game(data);
	if (keysym == 123 || keysym == 124 || keysym == 125 || keysym == 126
		|| keysym == 0 || keysym == 1 || keysym == 2 || keysym == 13)
	{
		value = repaint(*data, &data->map, keysym);
		if (value == 0)
		{
			write(1, "Movimientos: ", 13);
			ft_putnbr(data->map.mov++);
			write(1, "\n", 1);
		}
		else if (value == 2)
			end_game(data);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc != 2)
	{
		message_error(1, &map);
		return (1);
	}
	if (parse_file(argv[1], &map) == 1)
		return (1);
	data.map = map;
	if (init_window(&data, map) == 1)
		return (1);
	data.map.game = init_game(data, map);
	data.map.mov = 1;
	mlx_hook(data.win_ptr, 2, 1L << 0, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, &end_game, &data);
	mlx_loop(data.mlx_ptr);
	end_game(&data);
	return (0);
}

	//atexit(leaks);
	//system("leaks -q so_long");
