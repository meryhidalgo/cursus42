/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:14:44 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/09/13 14:28:18 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_message(char	*message, int p)
{
	if (p == 0)
		perror(message);
	else
		write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	double_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free (s);
}

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
