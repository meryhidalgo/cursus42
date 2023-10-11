/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mcarazo- <mcarazo-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/25 11:31:46 by mcarazo-		  #+#	#+#			 */
/*   Updated: 2023/09/25 11:46:49 by mcarazo-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../mlx/mlx.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1
#define XK_Escape 53

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF
#define BLACK_PIXEL 0x000000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; // bits per pixel
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

/*int close_window(int button, void *param)
{
	if (button == 17) //close button 
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("Keypress: %d\n", button);
	exit (0);
}*/

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		i++;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT - 100)
	{
		j = 0;
		while (j < WINDOW_WIDTH - 100)
			img_pix_put(img, j++, i, color);
		i++;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	//render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
	//	100, 100, GREEN_PIXEL});
	//render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */
void	repaint(t_data data, int x, int y)
{
	render_rect(&data.img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
		100, 100, BLACK_PIXEL});
	render_rect(&data.img, (t_rect){WINDOW_WIDTH - x, WINDOW_HEIGHT - y,
		100, 100, GREEN_PIXEL});
	//render_rect(&data.img, (t_rect){0, 0, 100, 100, RED_PIXEL});

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit (0); //*
	}
	if (keysym == 126)
	{
		repaint(*data, 100, 200);
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}


int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	//image
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
		&data.img.line_len,
			&data.img.endian);

	// Setup hooks
	mlx_loop_hook(data.mlx_ptr, &render, &data); //--> se usará para poner el fondo
	render_rect(&data.img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
		100, 100, GREEN_PIXEL});
	//render_rect(&data.img, (t_rect){0, 0, 100, 100, RED_PIXEL});

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);

	mlx_hook(data.win_ptr, 2, 1L<<0, &handle_keypress, &data);
	//mlx_key_hook(data.win_ptr, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	//mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
	return (0);
}

// https://aurelienbrabant.fr/blog?q=minilibx
// A S D W = 0 1 2 13
// <- -> down up = 123 124 125 126

//keysym https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
// https://reactive.so/post/42-a-comprehensive-guide-to-so_long

