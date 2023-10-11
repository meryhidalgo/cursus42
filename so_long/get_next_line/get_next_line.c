/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:01 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/02/21 18:12:36 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
			i++;
	}
	return (-1);
}

char	*return_line(char	**remainder, char *buffer, int x)
{
	char	*line;

	if (buffer)
		free(buffer);
	line = ft_strdup(*remainder, 0, x + 1, 0);
	*remainder = ft_strdup(*remainder, x + 1, ft_strlen(*remainder), 1);
	return (line);
}

char	*clean_remainder(char **remainder, char *line, int r)
{
	if (*remainder[0] && r != -1)
		line = ft_strdup(*remainder, 0, ft_strlen(*remainder), 1);
	else
		free(*remainder);
	*remainder = NULL;
	return (line);
}

char	*read_function(char **remainder, int fd, int x)
{
	char	*line;
	char	*buffer;
	int		r;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	r = read(fd, buffer, BUFFER_SIZE);
	line = NULL;
	while (r > 0)
	{
		if (!*remainder)
			*remainder = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		buffer[r] = '\0';
		*remainder = ft_strjoin(*remainder, buffer);
		x = check_line(*remainder);
		if (x >= 0)
			return (return_line(remainder, buffer, x));
		r = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (*remainder)
		return (clean_remainder(remainder, line, r));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	x = check_line(remainder);
	if (x >= 0)
		return (return_line(&remainder, NULL, x));
	return (read_function(&remainder, fd, x));
}
