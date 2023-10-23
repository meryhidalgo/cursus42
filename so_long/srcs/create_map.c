/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:21:52 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/23 13:21:55 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

int	init_window(t_data *data, t_map map)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, map.col * D_SIZE,
			map.row * D_SIZE, "So_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

void	set_player_exit(t_data data, t_map map, t_game game, int i[2])
{
	if (map.matrix[i[0]][i[1]] == 'P')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			game.pacL.img, D_SIZE * i[1], D_SIZE * i[0]);
	else if (map.matrix[i[0]][i[1]] == 'E')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			game.exit.img, D_SIZE * i[1], D_SIZE * i[0]);
	else
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			game.food.img, D_SIZE * i[1], D_SIZE * i[0]);
}

void	set_elements(t_data data, t_map map, t_game game)
{
	int	i[2];

	i[0] = 0;
	while (i[0] < map.row)
	{
		i[1] = 0;
		while (i[1] < map.col)
		{
			if (map.matrix[i[0]][i[1]] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					game.wall.img, D_SIZE * i[1], D_SIZE * i[0]);
			else if (map.matrix[i[0]][i[1]] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					game.cherry.img, D_SIZE * i[1], D_SIZE * i[0]);
			else
				set_player_exit(data, map, game, i);
			i[1]++;
		}
		i[0]++;
	}
}

t_game	init_game(t_data data, t_map map)
{
	int		len;
	t_game	game;

	len = D_SIZE;
	game.wall.img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/wall.xpm", &len, &len);
	game.food.img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/food.xpm", &len, &len);
	game.cherry.img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/cherry.xpm", &len, &len);
	game.pacR.img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/pac-R.xpm", &len, &len);
	game.pacL.img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/pac-L.xpm", &len, &len);
	game.pacD.img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/pac-D.xpm", &len, &len);
	game.pacU.img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/pac-U.xpm", &len, &len);
	game.black.img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/black.xpm", &len, &len);
	game.exit.img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/exit.xpm", &len, &len);
	set_elements(data, map, game);
	return (game);
}
