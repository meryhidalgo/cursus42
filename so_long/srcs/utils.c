/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:08:46 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/23 13:25:53 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../get_next_line/get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		if (i == length - 1)
			dest[i] = '\0';
		else
			dest[i] = src[i];
		i++;
	}
	return (length);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - start)
		substr = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
		return (NULL);
	while (s[i] != 0)
	{
		if (i >= start && j < len)
			substr[j++] = s[i];
		i++;
	}
	substr[j] = 0;
	return (substr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_zero(int *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
		s[i++] = 0;
}

void	message_error(int error, t_map *map)
{
	if (error == 1)
		write(1, "Error\nDebe introducir un archivo a parsear.\n", 45);
	else if (error == 2)
		write(1, "Error\nEl archivo no tiene extensión .ber.\n", 43);
	else if (error == 3)
		write(1, "Error\nEl mapa no es rectangular.\n", 34);
	else if (error == 4)
		write(1, "Error\nEl mapa no está rodeado de muros.\n", 41);
	else if (error == 5)
	{
		if (map->elements[0] < 1)
			write(1, "Error\nEl mapa debe tener mínimo un coleccionable.\n", 52);
		else if (map->elements[1] != 1)
			write(1, "Error\nEl mapa debe tener una salida.\n", 38);
		else if (map->elements[2] != 1)
			write(1, "Error\nEl mapa debe tener un jugador.\n", 38);
	}
	else if (error == 6)
		write(1, "Error\nNo hay un camino válido.\n", 32);
	else if (error == 7)
		write(1, "Error\nNo se puede abrir el archivo solicitado.\n", 48);
	else if (error == 8)
		write(1, "Error\nEl mapa debe únicamente contener 0, 1, P, C o E.\n", 56);
}
