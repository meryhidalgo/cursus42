/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:48:26 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/10/07 16:42:32 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;

	if (size < 0 || count < 0 || (size == SIZE_MAX && count == SIZE_MAX))
		return (NULL);
	space = malloc(size * count);
	if (space == 0)
		return (NULL);
	ft_bzero(space, size * count);
	return (space);
}
