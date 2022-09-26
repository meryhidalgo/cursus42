/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:14:03 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/26 18:00:15 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	length_dest;
	size_t	length_src;

	i = 0;
	if (dest == NULL && dstsize == 0)
		return (0);
	length_dest = ft_strlen(dest);
	length_src = ft_strlen(src);
	if (dstsize == 0 || dstsize <= length_dest)
		return (length_src + dstsize);
	while (src[i] != 0 && i < (dstsize - length_dest - 1))
	{
		dest[length_dest + i] = src[i];
		i++;
	}
	dest[length_dest + i] = 0;
	return (length_src + length_dest);
}
