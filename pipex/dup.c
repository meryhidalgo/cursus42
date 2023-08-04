/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:34:19 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/03 18:38:21 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("example", O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close (fd);
	printf("Este es un ejemplo de como deja de imprimir el mensaje por salida");
	printf(" estándar para guardarlo en el archivo example.");

	return (0);
}
