/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:52:11 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/25 08:22:55 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../get_next_line/get_next_line.h"

void	count_elements(char *row, t_map *map, int i)
{
	int	j;

	j = 0;
	while (j < map->col)
	{
		if (row[j] == 'C')
			map->elements[0]++;
		if (row[j] == 'E')
			map->elements[1]++;
		if (row[j] == 'P')
		{
			map->elements[2]++;
			map->player[1] = j;
			map->player[0] = i;
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
			count_elements(map->matrix[i], map, i);
			if (map->matrix[i][0] != '1' || map->matrix[i][map->col - 1] != '1')
				return (1);
		}
	}
	return (0);
}

int	check_all_paramters(t_map *map)
{
	int		i;
	char	**matrix2;

	i = 0;
	ft_zero(map->elements, 3);
	ft_zero(map->player, 2);
	if (through_matrix(map) == 1)
		return (4);
	if (map->elements[0] < 1 || map->elements[1] != 1 || map->elements[2] != 1)
		return (5);
	matrix2 = copy_matrix(map);
	fill(matrix2, &map->elements, map->player[0], map->player[1]);
	if (map->elements[0] > 0 || map->elements[1] > 0)
		return (6);
	ft_zero(map->elements, 3);
	while (i < map->row)
	{
		count_elements(map->matrix[i], map, i);
		free (matrix2[i++]);
	}
	free(matrix2);
	return (0);
}

int	parse_map(char *file, int fd, char *c, t_map *map)
{
	int	error;

	fd = open(file, O_RDONLY);
	c = get_next_line(fd);
	map->col = ft_strlen(c);
	(map->row)--;
	if (create_matrix(fd, c, map) == 1)
		return (1);
	if (other_element(map) == 1)
	{
		message_error(8, map);
		return (1);
	}
	(map->col)--;
	error = check_all_paramters(map);
	if (error != 0)
	{
		message_error(error, map);
		return (1);
	}
	return (0);
}

int	parse_file(char *file, t_map *map)
{
	int		fd;
	char	*c;
	char	*ext;

	map->row = 1;
	ext = ft_substr(file, ft_strlen(file) - 4, ft_strlen(file));
	if (ft_strncmp(ext, ".ber", 4) != 0)
	{
		free(ext);
		message_error(2, map);
		return (1);
	}
	free(ext);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		message_error(7, map);
		return (1);
	}
	c = get_next_line(fd);
	count_rows(fd, c, map);
	close (fd);
	return (parse_map(file, fd, c, map));
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
