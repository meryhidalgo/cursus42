/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:03:10 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/26 16:20:20 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countwords(char const *s, char c)
{
	int	i;
	int	d;
	int	total;

	i = 0;
	d = 0;
	total = 0;
	while (s[i] != 0)
	{
		if (s[i] == c && d != 0 && s[i + 1] != c && s[i + 1] != 0)
			total++;
		if (s[i] != c)
			d = 1;
		i++;
	}
	if (d == 0)
		return (0);
	return (total + 1);
}

char	*fill_word(char const *s, int j)
{
	int		k;
	char	*str;

	k = 0;
	str = (char *)malloc(sizeof(char) * j + 1);
	if (str == 0)
	{
		free(str);
		return (0);
	}
	while (k < j)
	{
		str[k] = s[k];
		k++;
	}
	str[k] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**sol;
	int		i[2];

	i[0] = 0;
	if (s == 0)
		return (NULL);
	sol = (char **)malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (sol == 0)
	{
		free(sol);
		return (NULL);
	}
	while (*s != 0)
	{
		i[1] = 0;
		while (*s == c)
			s++;
		while (s[i[1]] != c && s[i[1]] != 0)
			i[1]++;
		if (*s != 0)
			sol[i[0]++] = fill_word(s, i[1]);
		s = s + i[1];
	}
	sol[i[0]] = 0;
	return (sol);
}
