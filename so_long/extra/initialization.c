/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:21:48 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/09/25 11:36:19 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

/*  Let’s create a window with the name of “Hello world!
To achieve this, we will simply call the mlx_new_window function, 
which will return a pointer to the window we have just created. 
We can give the window height, width and a title. We then will have to 
call mlx_loop to initiate the window rendering.”

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
*/

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// int offset = (y * line_length + x * (bits_per_pixel / 8));

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
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
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);
}

/* We must understand that the bytes are not aligned, this means that the 
line_length differs from the actual window width. We therefore should ALWAYS 
calculate the memory offset using the line length set by mlx_get_data_addr.*/
