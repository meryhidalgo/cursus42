/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacarazohidalgo <mariacarazohidalgo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:01 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/02/13 23:38:47 by mariacarazo      ###   ########.fr       */
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

char	*return_line(char	**remainder, char *line, char *buffer, int x)
{
	if (buffer)
		free(buffer);
	line = ft_strdup(*remainder, 0, x + 1, 0);
	*remainder = ft_strdup(*remainder, x + 1, ft_strlen(*remainder), 1); //1 o 2?????
	return (line);
}

char	*read_function(char **remainder, char *line, int fd, int x)
{
	char		*buffer;
	int			r;
		
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		if (!*remainder)
			*remainder = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		buffer[r] = '\0';
		*remainder = ft_strjoin(*remainder, buffer);
		x = check_line(*remainder);
		if (x >= 0)
			return(return_line(remainder, line, buffer, x));
		ft_bzero(buffer, BUFFER_SIZE + 1);
		r = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (*remainder)
	{
		line = ft_strdup(*remainder, 0, ft_strlen(*remainder), 1);
		*remainder = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line; 
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	x = check_line(remainder);
	if (x >= 0)
		return (return_line(&remainder, line, NULL, x));
	return(read_function(&remainder, line, fd, x));
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*c = "A";

	fd = open(argv[1], O_RDONLY);
	//fd = open("test", O_RDONLY);
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
