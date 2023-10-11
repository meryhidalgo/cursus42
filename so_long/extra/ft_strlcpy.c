/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:07:59 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/26 17:49:07 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
