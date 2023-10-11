/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:43:02 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/09/27 12:49:52 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	render_next_frame(void *mlx, void *mlx_win, t_data img)
{
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	return(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	/* After creating an image, we can call `mlx_get_data_addr`, we pass
		`bits_per_pixel`, `line_length`, and `endian` by reference. These will
		then be set accordingly for the *current* data address. */
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 4;
	while (++i < 500)
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
	// 0x00FF0000 is the hex representation of ARGB(0,255,0,0).
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop_hook(mlx, render_next_frame, mlx_win);
	mlx_loop(mlx);
}
