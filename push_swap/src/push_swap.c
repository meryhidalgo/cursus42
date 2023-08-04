/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:35:01 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/02 15:16:36 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	if_rotate(t_list **st_b, int k, int total)
{
	if (k <= total / 2 && k != 0)
	{
		while (k-- != 0)
			rotate(st_b, 'B');
	}
	else if (k > total / 2 && k != 0)
	{
		while (k++ != total)
			rrotate(st_b, 'B');
		k = 0;
	}
}

void	push_back_sorted(t_list **st_a, t_list **st_b, int *sor, int total)
{
	int	*tab;
	int	k;

	while (*st_b != NULL)
	{
		k = 0;
		tab = stack_to_array(*st_b);
		while (k < total)
		{
			if (tab[k] == sor[total - 1])
				break ;
			k++;
		}
		if_rotate(st_b, k, total);
		push(st_b, st_a, 'A');
		total--;
		free (tab);
	}
}

void	search_nb_to_push(t_list **st_a, t_list **st_b, int range[2], int *sor)
{
	int	j;
	int	fst;
	int	snd;
	int	*tab;

	while (ft_lstsize(*st_a) > (range[0] - range[1]) && ft_lstsize(*st_a) > 3)
	{
		tab = stack_to_array(*st_a);
		fst = upwards(tab, sor, range, ft_lstsize(*st_a));
		snd = downwards(tab, sor, range, ft_lstsize(*st_a));
		j = 0;
		if (fst <= (ft_lstsize(*st_a) - snd - 1))
			while (j++ < fst)
				rotate(st_a, 'A');
		else
		{
			while (j++ < ft_lstsize(*st_a) - snd)
				rrotate(st_a, 'A');
		}
		push(st_a, st_b, 'B');
		free (tab);
	}
}

void	push_to_b(t_list **st_a, t_list **st_b, int ch, int *sorted)
{
	int	mult;
	int	range[2];

	mult = 1;
	range[0] = ft_lstsize(*st_a);
	while (ft_lstsize(*st_a) > 3)
	{
		range[1] = ch * mult;
		search_nb_to_push(st_a, st_b, range, sorted);
		mult++;
	}
	sort_three(st_a);
}

void	push_swap(t_list **st_a, t_list **st_b)
{
	int	total;
	int	chunks;
	int	*tab;
	int	*sorted;

	total = ft_lstsize(*st_a);
	if (total <= 3)
	{
		sort_three(st_a);
		return ;
	}
	chunks = nb_chunks(total);
	tab = stack_to_array(*st_a);
	if (ft_issorted(st_a, tab, total) == 1)
		return ;
	sorted = trunc_sorted(sorted_array(tab, total), total);
	tab = NULL;
	free (tab);
	push_to_b(st_a, st_b, chunks, sorted);
	push_back_sorted(st_a, st_b, sorted, total - 3);
	free(sorted);
}

	/*printf("A ");
	print_list(*st_a);
	printf("B ");
	print_list(*st_b);*/
