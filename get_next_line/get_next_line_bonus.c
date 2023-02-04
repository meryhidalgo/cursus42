/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:04:17 by mariacarazo       #+#    #+#             */
/*   Updated: 2023/02/02 20:17:02 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	errores(char *check)
{
	if (!check[0])
	{
		free(check);
		return (-1);
	}
	return (1);
}

int	check_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && i < BUFFER_SIZE)
	{
		if (s[i] == '\n' || s[i] == '\0')
			return (i);
		else
			i++;
	}
	return (i);
}

char	*read_line(int fd, char *line, char **remainder)
{
	int		x;
	char	*buffer;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (read(fd, buffer, BUFFER_SIZE) == -1)
	{
		if (line)
			free (line);
		free(buffer);
		return (NULL);
	}
	if (errores(buffer) < 0)
		return (line);
	x = check_line(buffer);
	if (!line)
		line = (char *)ft_calloc((x + 2), sizeof(char));
	while (x == BUFFER_SIZE)
	{
		line = ft_strjoin(line, buffer);
		ft_bzero(buffer, ft_strlen(buffer));
		if (read(fd, buffer, BUFFER_SIZE) == -1)
		{
			if (line)
				free (line);
			free(buffer);
			return (NULL);
		}
		if (errores(buffer) < 0)
			return (line);
		x = check_line(buffer);
	}
	line = ft_strjoin(line, buffer);
	if (x != (BUFFER_SIZE - 1))
		remainder[fd] = ft_strdup(&buffer[x + 1]);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	int			x;
	char		*line;
	char		*aux;
	static char	*remainder[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder[fd])
	{
		if (errores(remainder[fd]) < 0)
			return (NULL);
		line = ft_strdup(remainder[fd]);
		x = check_line(remainder[fd]);
		if (x < (int)ft_strlen(remainder[fd]))
		{
			line[x + 1] = 0;
			aux = ft_strdup(&(remainder[fd][x + 1]));
			free(remainder[fd]);
			remainder[fd] = aux;
			return (line);
		}
		free(remainder[fd]);
		remainder[fd] = NULL;
	}
	else
		line = NULL;
	return (read_line(fd, line, remainder));
}

/*int	main(int argc, char **argv)
{
	int	fd[4];
	char	*c;

	fd[1] = open(argv[1], O_RDONLY);
	fd[2] = open(argv[2], O_RDONLY);
	c = get_next_line(1001);
	printf("string 1 %s\n", c);
	free (c);
	
	c = get_next_line(fd[1]);
	printf("string 2 %s", c);
	free (c);

	c = get_next_line(1002);
	printf("string 3 %s\n", c);
	free (c);
	
	c = get_next_line(fd[2]);
	printf("string 4 %s", c);
	free (c);

	c = get_next_line(1003);
	printf("string 5 %s\n", c);
	free (c);

	c = get_next_line(fd[1]);
	printf("string 6 %s", c);
	free (c);

	close(fd[1]);
	close(fd[2]);
	system("leaks -q a.out");
}*/
