/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:52:11 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/11 10:34:17 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../get_next_line/get_next_line.h"

/*
- Extensión .ber ???? */

void	count_elements(char *row, int elements[][3], int player[][2], int cols)
{
	int	j;

	j = 0;
	while (j < cols)
	{
		if (row[j] == 'C')
			(*elements)[0]++;
		if (row[j] == 'E')
			(*elements)[1]++;
		if (row[j] == 'P')
		{
			(*elements)[2]++;
			(*player)[1] = j;
		}
		j++;
	}
}

int	through_matrix(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->row)
	{
		if (i == 0 || i == (map->row - 1))
		{
			j = 0;
			while (map->matrix[i][j])
			{
				if (map->matrix[i][j++] != '1')
					return (1);
			}
		}
		else
		{
			count_elements(map->matrix[i], &(map->elements),
				&(map->player), map->col);
			if (map->matrix[i][0] != '1' || map->matrix[i][map->col - 1] != '1')
				return (1);
			if (map->player[1] != 0)
				map->player[0] = i - 1;
		}
	}
	return (0);
}

int	check_all_paramters(t_map *map)
{
	int		i;
	int		result;
	char	**matrix2;

	i = 0;
	result = 0;
	map->elements[0] = 0;
	map->elements[1] = 0;
	map->elements[2] = 0;
	map->player[0] = 0;
	map->player[1] = 0;
	if (through_matrix(map) == 1)
		result = 1;
	if (map->elements[0] < 1 || map->elements[1] != 1 || map->elements[2] != 1)
		result = 1;
	matrix2 = copy_matrix(map);
	fill(matrix2, &map->elements, map->player[0], map->player[1]);
	if (map->elements[0] != 0 || map->elements[1] != 0)
		result = 1;
	while (i < map->row)
		free (matrix2[i++]);
	free(matrix2);
	return (result);
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
			printf("Error\n");
			return (1);
		}
		ft_strlcpy(map->matrix[i], c, map->col);
		free (c);
		c = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

int	parse_file(char *file, t_map *map)
{
	int		fd;
	char	*c;

	map->row = 1;
	fd = open(file, O_RDONLY);
	c = get_next_line(fd);
	count_rows(fd, c, map);
	close (fd);
	fd = open(file, O_RDONLY);
	c = get_next_line(fd);
	map->col = ft_strlen(c);
	(map->row)--;
	if (create_matrix(fd, c, map) == 1)
		return (1);
	(map->col)--;
	if (check_all_paramters(map) == 1)
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	t_map	map;
	int		i;

	if (parse_file(argv[1], &map) == 1)
		return (1);

	i = 0;
	while (i < map.row)
	{
		printf("%s\n", map.matrix[i]);
		i++;
	}
	//system("leaks -q so_long");
	argc++;
	return (0);
}*/
