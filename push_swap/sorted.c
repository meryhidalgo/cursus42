/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:08:15 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/03 10:54:24 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_list *stack)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * (ft_lstsize(stack) + 1));
	while (stack)
	{
		tab[i++] = stack->content;
		stack = stack->next;
	}
	return (tab);
}

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
