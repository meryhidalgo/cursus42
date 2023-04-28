/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:08:15 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/28 20:04:53 by mcarazo-         ###   ########.fr       */
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

void	sort_three(t_list **stack_A, int *tab)
{
	int	*aux;
	int	*sorted;

	aux = stack_to_array(*stack_A);
	sorted = sorted_array(aux, ft_lstsize(*stack_A));
	free (aux);
	if (tab[0] == sorted[0] && tab[1] == sorted[1])
		return ;
	else if (tab[0] == sorted[1] && tab[1] == sorted[2])
		rrotate(stack_A, 'A');
	else if (tab[1] == sorted[0] && tab[2] == sorted[1])
		rotate(stack_A, 'A');
	else
	{
		swap(stack_A, 'A');
		free (tab);
		sort_three(stack_A, stack_to_array(*stack_A));
	}
	free (tab);
}
