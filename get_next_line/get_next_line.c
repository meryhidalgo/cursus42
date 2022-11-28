/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacarazohidalgo <mariacarazohidalgo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:04:17 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/11/15 14:17:11 by mariacarazo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	next_line(char *buffer)
{
	int	i;
	
	i = 0;
	while (buffer[i] && i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (0);
		else 
			i++;	
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	int		n;
	
	n = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE * n);
	read(fd, buffer, BUFFER_SIZE);
	//copy buffer en line
	while (next_line(buffer))
	{
		n++;
		free (line);
		line = (char *)malloc(sizeof(char) * BUFFER_SIZE * n);
		read(fd, buffer, BUFFER_SIZE);
		//copy buffer en line PERO NO MANTENGO LA INFO ANTERIOR
	}
	free(buffer);
	return (line);
}
