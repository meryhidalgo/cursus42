/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:23:07 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/23 13:22:33 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define D_SIZE 64
# define MLX_ERROR 1
# define XK_ESC 53

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_game
{
	t_img	wall;
	t_img	food;
	t_img	cherry;
	t_img	pacR;
	t_img	pacL;
	t_img	pacD;
	t_img	pacU;
	t_img	black;
	t_img	exit;
}	t_game;

typedef struct s_map
{
	int		row;
	int		col;
	char	**matrix;
	int		player[2];
	int		elements[3];
	int		mov;
	t_game	game;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_data;

void	message_error(int error, t_map *map);
int		parse_file(char *file, t_map *map);
int		create_matrix(int fd, char *c, t_map *map);
char	**copy_matrix(t_map *map);
void	count_rows(int fd, char *c, t_map *map);
void	ft_zero(int *s, size_t n);
void	ft_putnbr(int nb);
size_t	ft_strlcpy(char *dest, const char *src, size_t length);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	fill(char **matrix, int elements[][3], int row, int col);
int		other_element(t_map *map);
int		init_window(t_data *data, t_map map);
t_game	init_game(t_data data, t_map map);
int		move_player(int keysym, t_map *map);

#endif
