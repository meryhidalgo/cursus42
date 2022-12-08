/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:15:51 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/12/08 13:29:42 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = 0;
	while (src[length] != 0)
		length++;
	while (i < length + 1 && i < dstsize)
	{
		if (i == dstsize - 1)
			dest[i] = '\0';
		else
			dest[i] = src[i];
		i++;
	}
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
	//free((void *)s1);
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
	j = 0;
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	while (s2 [j] != '\n' && s2[j] != 0)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = s2[j];
	join[i + 1] = '\0';
	free(s1);
	return (join);
}
