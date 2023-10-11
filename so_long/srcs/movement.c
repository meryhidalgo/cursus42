/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:58:11 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/11 12:47:25 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

void	destroy_every_image(t_data *data, t_game *game)
{
	mlx_destroy_image(data->mlx_ptr, game->wall.img);
	mlx_destroy_image(data->mlx_ptr, game->food.img);
	mlx_destroy_image(data->mlx_ptr, game->cherry.img);
	mlx_destroy_image(data->mlx_ptr, game->pac.img);
}

void	black_and_pac(t_data data, t_map *map, int x, int y)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.black.img,
		D_SIZE * x, D_SIZE * y);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.black.img,
		D_SIZE * map->player[1], D_SIZE * map->player[0]);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map->game.pac.img,
		D_SIZE * map->player[1], D_SIZE * map->player[0]);
}

int	repaint(t_data data, t_map *map, int keysym)
{
	int	x;
	int	y;

	x = map->player[1];
	y = map->player[0];
	if (keysym == 123 || keysym == 0)
	{
		if (map->matrix[map->player[0]][map->player[1] - 1] == '1')
			return (1);
		map->player[1]--;
	}
	else if (keysym == 124 || keysym == 2)
	{
		if (map->matrix[map->player[0]][map->player[1] + 1] == '1')
			return (1);
		map->player[1]++;
	}
	else if (keysym == 125 || keysym == 1)
	{
		if (map->matrix[map->player[0] + 1][map->player[1]] == '1')
			return (1);
		map->player[0]++;
	}
	else
	{
		if (map->matrix[map->player[0] - 1][map->player[1]] == '1')
			return (1);
		map->player[0]--;
	}
	black_and_pac(data, map, x, y);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		//destroy_every_image(data, game);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		//free(data->win_ptr);
		//free(data->mlx_ptr);
		exit (0);
	}
	printf("player: %d %d\n", data->map.player[0],  data->map.player[1]);
	if (keysym == 123 || keysym == 124 || keysym == 125 || keysym == 126
		|| keysym == 0 || keysym == 1 || keysym == 2 || keysym == 13)
		{
			if (repaint(*data, &data->map, keysym) == 0)
				printf("Movimientos: %d\n", data->map.mov++);
		}
	//printf("Keypress: %d\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (parse_file(argv[1], &map) == 1)
		return (1);
	data.map = map;
	if (init_window(&data, map) == 1)
		return (1);
	data.map.game = init_game(data, map);
	data.map.mov = 1;
	//printf("player: %d %d\n", data.map.player[0],  data.map.player[1]);
	// usar mlx_loop_hook para el fondo????
	mlx_hook(data.win_ptr, 2, 1L << 0, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	destroy_every_image(&data, &map.game);
	data.win_ptr = NULL;
	free(data.win_ptr);
	free(data.mlx_ptr);
	//system("leaks -q so_long");
	return (0);
	argc++;
}

// no me deja ejecutar con sanitize
