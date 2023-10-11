/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:58:11 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/11 10:34:38 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

void	destroy_every_image(t_data *data, t_game *game)
{
	mlx_destroy_image(data->mlx_ptr, game->wall.mlx_img);
	mlx_destroy_image(data->mlx_ptr, game->food.mlx_img);
	mlx_destroy_image(data->mlx_ptr, game->cherry.mlx_img);
	mlx_destroy_image(data->mlx_ptr, game->pac.mlx_img);
}

void	repaint(t_data data, t_game game, int x, int y)
{
	int		len;

	len = D_SIZE;
	game.black.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr,
			"./images/white.xpm", &len, &len);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					game.black.mlx_img, D_SIZE * y, D_SIZE * x);
}

int	handle_keypress(int keysym, t_data *data, t_game *game, t_map *map)
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
	if (keysym == 124)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			game->black.mlx_img, D_SIZE * map->player[1], D_SIZE * map->player[0]);
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	t_game	game;

	if (parse_file(argv[1], &map) == 1)
		return (1);
	if (init_window(&data, map) == 1)
		return (1);
	game = init_game(data, map);
	// usar mlx_loop_hook para el fondo????
	mlx_hook(data.win_ptr, 2, 1L << 0, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	destroy_every_image(&data, &game);
	data.win_ptr = NULL;
	free(data.win_ptr);
	free(data.mlx_ptr);
	system("leaks -q so_long");
	return (0);
	argc++;
}

// no me deja ejecutar con sanitize
