/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:08:46 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/10/11 12:13:57 by mcarazo-         ###   ########.fr       */
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
