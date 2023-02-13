/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacarazohidalgo <mariacarazohidalgo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:04:17 by mariacarazo       #+#    #+#             */
/*   Updated: 2023/02/13 23:41:27 by mariacarazo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check(char *c)
{
	if (!c[0])
	{
		free(c);
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
	if (check(buffer) < 0)
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
		if (check(buffer) < 0)
			return (line);
		x = check_line(buffer);
	}
	line = ft_strjoin(line, buffer);
	if (x != (BUFFER_SIZE - 1))
		*remainder = ft_strdup(&buffer[x + 1]);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	int			x;
	char		*line;
	char		*aux;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder)
	{
		if (check(remainder) < 0)
			return (NULL);
		line = ft_strdup(remainder);
		x = check_line(remainder);
		if (x < (int)ft_strlen(remainder))
		{
			line[x + 1] = 0;
			aux = ft_strdup(&remainder[x + 1]);
			free(remainder);
			remainder = aux;
			return (line);
		}
		free(remainder);
		remainder = NULL;
	}
	else
		line = NULL;
	return (read_line(fd, line, &remainder));
}

void	leaks()
{
	system("leaks -q a.out\n");
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*c = "A";

	//atexit(leaks);
	fd = open(argv[1], O_RDONLY);
	//fd = open("42_no_nl", O_RDONLY);
	while (c)
	{
		c = get_next_line(fd);
		printf("%s", c);
		free(c);
	}
	close(fd);
	argc++;
	//system("leaks -q a.out");
}
