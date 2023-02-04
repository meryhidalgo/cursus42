/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:15:51 by mariacarazo       #+#    #+#             */
/*   Updated: 2023/01/24 11:13:08 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == 0 || s1 == 0)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + check_line(s2) + 2));
	if (join == 0)
		return (NULL);
	i = ft_strlen(s1);
	j = -1;
	while (j++ < i)
		join[j] = s1[j];
	join[j] = '\0';
	j = 0;
	while (s2 [j] != '\n' && s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = s2[j];
	join[i + 1] = '\0';
	free(s1);
	return (join);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*space;

	if (size < 0 || count < 0 || (count != 0 && (SIZE_MAX / count) < size))
		return (NULL);
	space = malloc(size * count);
	if (space == 0)
		return (NULL);
	i = 0;
	while (i < (size * count))
		((unsigned char *)space)[i++] = '\0';
	return (space);
}
