/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:54:47 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/09/26 16:20:49 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fstr;

	i = 0;
	if (s == 0)
		return (NULL);
	fstr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (fstr == 0)
		return (NULL);
	while (s[i] != 0)
	{
		fstr[i] = f(i, s[i]);
		i++;
	}
	fstr[i] = 0;
	return (fstr);
}
