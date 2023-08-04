/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:03:10 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/01 17:35:24 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

static char	*fill_word(char const *s, char **sol, int j, int i)
{
	int		k;

	k = 0;
	sol[i] = (char *)malloc(sizeof(char) * (j + 1));
	if (sol[i] == NULL)
	{
		while (i >= 0)
		{
			free(sol[i]);
			i--;
		}
		free(sol);
		return (NULL);
	}
	while (k < j)
	{
		sol[i][k] = s[k];
		k++;
	}
	sol[i][k] = 0;
	return (sol[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**sol;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	sol = (char **)malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!sol)
		return (NULL);
	while (*s != 0)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] != c && s[j] != 0)
			j++;
		if (*s != 0)
			if (!fill_word(s, sol, j, i++))
				return (NULL);
		s = s + j;
	}
	sol[i] = 0;
	return (sol);
}
