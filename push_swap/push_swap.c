/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:35:01 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/28 20:09:43 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	nb_chunks(int length)
{
	if (length < 20) //menos de 4 debería organizarse sin pb, con 5?????
		return (5);
	else if (length < 50)
		return (10);
	else if (length < 100)
		return (20);
	else
		return (50);
}

void	push_back_sorted(t_list **stack_A, t_list **stack_B, int *sorted, int total)
{
	int	*tab;
	int	k;

	k = 0;
	while (*stack_B != NULL)
	{
		tab = stack_to_array(*stack_B);
		while (k < total)
		{
			if (tab[k] == sorted[total - 1])
				break ;
			k++;
		}
		if (k <= total / 2 && k != 0)
		{
			while (k-- != 0)
				rotate(stack_B, 'B');
		}
		else if (k > total / 2 && k != 0)
		{
			while (k++ != total)
				rrotate(stack_B, 'B');
			k = 0;
		}
		push(stack_B, stack_A, 'A');
		total--;
		free (tab);
	}
}

void	push_to_B(t_list **stack_A, t_list **stack_B, int total, int num, int *tab, int *sorted)
{
	int	j;
	int	mult;
	int	hold_fst;
	int	hold_snd;

	mult = 1;
	//while (ft_lstsize(*stack_A) > 3)
	while (*stack_A != NULL)
	{
		while (ft_lstsize(*stack_A) > (total - num * mult)
			&& ft_lstsize(*stack_A) != 0)
		{
			tab = stack_to_array(*stack_A);
			hold_fst = upwards(tab, sorted, num * mult, ft_lstsize(*stack_A));
			hold_snd = downwards(tab, sorted, num * mult, ft_lstsize(*stack_A));
			j = 0;
			/*if (hold_fst == -1 || hold_snd == -1)
			{
				printf("HOLI");
				continue ;
			}*/
			if (hold_fst <= (ft_lstsize(*stack_A) - hold_snd - 1))
			{
				while (j++ < hold_fst)
					rotate(stack_A, 'A');
			}
			else
			{
				while (j++ < ft_lstsize(*stack_A) - hold_snd)
					rrotate(stack_A, 'A');
			}
			push(stack_A, stack_B, 'B');
			free (tab);
		}
		mult++;
	}
	//sort_three(stack_A, stack_to_array(*stack_A));
}

void	push_swap(t_list **stack_A, t_list **stack_B)
{
	int	total;
	int	num;
	int	*tab;
	int	*sorted;

	total = ft_lstsize(*stack_A);
	if (total <= 3)
	{
		sort_three(stack_A, stack_to_array(*stack_A));
		return ;
	}
	num = nb_chunks(total);
	tab = stack_to_array(*stack_A);
	sorted = sorted_array(tab, total);
	tab = NULL;
	free (tab);
	push_to_B(stack_A, stack_B, total, num, tab, sorted);
	push_back_sorted(stack_A, stack_B, sorted, total); // total - 3
}

	/* hay que truncar sorted y quitarle los tres ultimos, de manera que cuando 
	hold_fst o hold_snd sean -1 significa que no ha encontrado y corresponderán 
	con los tres últimos. Estos deberían ignorarse hasta que 
	el tamaño de stack A sea 3. en ese mommento ordeno y back*/
