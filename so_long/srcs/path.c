/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:17:35 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/23 12:12:45 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../get_next_line/get_next_line.h"

int	other_element(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col - 1)
		{
			if (map->matrix[i][j] != '0' && map->matrix[i][j] != '1'
				&& map->matrix[i][j] != 'E' && map->matrix[i][j] != 'C'
				&& map->matrix[i][j] != 'P' )
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	fill(char **matrix, int elements[][3], int row, int col)
{
	if (matrix[row][col] == 'C')
		(*elements)[0]--;
	if (matrix[row][col] == 'E')
		(*elements)[1]--;
	if ((*elements)[0] == 0 && (*elements)[1] == 0)
		return ;
	if (matrix[row][col] == '1' || matrix[row][col] == '2')
		return ;
	matrix[row][col] = '2';
	fill(matrix, elements, row - 1, col);
	fill(matrix, elements, row, col + 1);
	fill(matrix, elements, row + 1, col);
	fill(matrix, elements, row, col - 1);
}

char	**copy_matrix(t_map *map)
{
	int		i;
	char	**matrix2;

	i = 0;
	matrix2 = (char **)malloc((map->row) * sizeof(char *));
	while (i < map->row)
		matrix2[i++] = (char *)malloc((map->col + 1) * sizeof(char));
	i = 0;
	while (i < map->row)
	{
		ft_strlcpy(matrix2[i], map->matrix[i], map->col + 1);
		i++;
	}
	return (matrix2);
}

void	count_rows(int fd, char *c, t_map *map)
{
	while (c)
	{
		free (c);
		c = get_next_line(fd);
		(map->row)++;
	}
}

int	create_matrix(int fd, char *c, t_map *map)
{
	int	i;

	map->matrix = (char **)malloc(map->row * sizeof(char *));
	i = 0;
	while (i < map->row)
		map->matrix[i++] = (char *)malloc(map->col * sizeof(char));
	i = 0;
	while (c)
	{
		if ((int)ft_strlen(c) != map->col)
		{
			message_error(3, map);
			return (1);
		}
		ft_strlcpy(map->matrix[i], c, map->col);
		free (c);
		c = get_next_line(fd);
		i++;
	}
	free(c);
	close(fd);
	return (0);
}
