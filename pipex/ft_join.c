/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:02:57 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/03 17:15:57 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_join(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == 0)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	while (s2[j] != 0)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = 0;
	free(s1);
	return (join);
}
