/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:04:17 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/12/01 17:32:39 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		else
			i++;
	}
	return (i);
}

char	*join_buffer_line(int fd, char *buffer, char *line, char **remainder)
{
	int	n;

	n = 1;
	while (check_line(buffer) == BUFFER_SIZE)
	{
		n++;
		line = ft_strjoin(line, buffer);
		read(fd, buffer, BUFFER_SIZE);
		buffer[ft_strlen(buffer)] = 0;
	}
	if (n > 1)
		line = ft_strjoin(line, buffer);
	else
		line = ft_strjoin(line, buffer);
	line[ft_strlen(line)] = '\n';
	*remainder = ft_strdup(&buffer[check_line(buffer) + 1]);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = 0;
	if (check_line(buffer) == 0)
	{
		free(buffer);
		return (NULL);
	}
	if (remainder)
		line = ft_strdup(remainder);
	else
		line = (char *)malloc(sizeof(char) * check_line(buffer) + 1);
	return (join_buffer_line(fd, buffer, line, &remainder));
}

/*int	main()
{
	int	fd;
	int	i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	while (i < 5)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
}*/
