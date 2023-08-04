/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:08:15 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/02 15:54:06 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*sorted_array(int *tab, int size)
{
	int	pos;
	int	i;
	int	min;
	int	aux;

	pos = 0;
	while (pos < size - 1)
	{
		i = pos + 1;
		min = pos;
		while (i < size)
		{
			if (tab[i] <= tab[min])
				min = i;
			i++;
		}
		aux = tab[pos];
		tab[pos] = tab[min];
		tab[min] = aux;
		pos++;
	}
	return (tab);
}

int	*trunc_sorted(int *sorted, int size)
{
	int	j;
	int	*trunc;

	j = 0;
	trunc = (int *)malloc(sizeof(int) * (size - 3));
	while (j < (size - 3))
	{
		trunc[j] = sorted[j];
		j++;
	}
	return (trunc);
}

void	ft_free(int *tab, int *sorted)
{
	free (tab);
	free (sorted);
}

void	sort_three(t_list **stack_a)
{
	int	*tab;
	int	*sorted;

	sorted = stack_to_array(*stack_a);
	sorted = sorted_array(sorted, ft_lstsize(*stack_a));
	tab = stack_to_array(*stack_a);
	if (tab[0] == sorted[0] && tab[1] == sorted[1])
	{
		ft_free(tab, sorted);
		return ;
	}
	else if (tab[0] == sorted[1] && tab[1] == sorted[2])
		rrotate(stack_a, 'A');
	else if (tab[1] == sorted[0] && tab[2] == sorted[1])
		rotate(stack_a, 'A');
	else
	{
		swap(stack_a, 'A');
		ft_free(tab, sorted);
		tab = NULL;
		sorted = NULL;
		sort_three(stack_a);
	}
	ft_free(tab, sorted);
}

int	ft_issorted(t_list **stack_a, int *tab, int total)
{
	int	i;
	int	*tab2;
	int	*sorted;

	i = 0;
	tab2 = stack_to_array(*stack_a);
	sorted = sorted_array(tab2, total);
	while (i < total)
	{
		if (tab[i] != sorted[i])
		{	
			free(tab2);
			return (0);
		}
		i++;
	}
	total++;
	free(tab2);
	return (1);
}
