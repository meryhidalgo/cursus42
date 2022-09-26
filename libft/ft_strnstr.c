/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:58:44 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/26 16:26:52 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ocurrence;

	i = 0;
	j = 0;
	if (len == 0 && haystack == NULL)
		return (NULL);
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && needle[j] != 0 && i + j < len)
	{
		if (haystack[i + j] == needle[j])
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	ocurrence = (char *)haystack + i;
	if (j > 0 && needle[j] == 0)
		return (ocurrence);
	else
		return (0);
}
