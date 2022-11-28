/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacarazohidalgo <mariacarazohidalgo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:15:51 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/11/15 14:16:31 by mariacarazo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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