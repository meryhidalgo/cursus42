/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:48:26 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/26 20:28:27 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;
	size_t	i;

	i = 0;
	if (size < 0 || count < 0 || size * count > SIZE_MAX)
		return (0);
	space = malloc(size * count);
	if (space == 0)
		return (0);
	while (i < size * count)
	{
		((unsigned char *)space)[i] = 0;
		i++;
	}
	return (space);
}
