/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:07:24 by mariacarazo       #+#    #+#             */
/*   Updated: 2023/02/21 17:17:13 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
		((unsigned char *)s)[i++] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;

	if (size < 0 || count < 0 || (count != 0 && (SIZE_MAX / count) < size))
		return (NULL);
	space = malloc(size * count);
	if (space == 0)
		return (NULL);
	ft_bzero(space, size * count);
	return (space);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*ft_strdup(char *s1, int start, int end, int x)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)ft_calloc((end - start + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	if (x == 1 && s1)
		free(s1);
	return (ptr);
}
