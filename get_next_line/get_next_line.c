/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:05:36 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/11/21 19:39:19 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_line(char *s)
{
	int	i;

	i = 0;
	getchar();
	while (s[i] != '\n' || s[i] != 0)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char	*str;
	char	*line;

	read(fd, &str, BUFFER_SIZE);
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	//line = str;
	while (read_line(str) == BUFFER_SIZE)
	{
		free(line);
		line = ft_strjoin(line, str);
		//str = (char *)ft_bzero((void *)str, BUFFER_SIZE);
		read(fd, &str, BUFFER_SIZE);
	}
	return (line);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
