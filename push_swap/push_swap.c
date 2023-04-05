/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:35:01 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/05 12:45:25 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	upwards(int *tab, int *sorted, int num, int total)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	while (i < total)
	{
		j = 0;
		while (j < num)
		{
			if (tab[i] == sorted[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	downwards(int *tab, int *sorted, int num, int total)
{
	int	i;
	int	j;
	int	pos;

	i = total;
	while (i >= 0)
	{
		j = 0;
		while (j < num)
		{
			if (tab[i] == sorted[j])
				return (i);
			j++;
		}
		i--;
	}
	return (-1);
}

void	sort(t_list *stack_A, t_list *stack_B)
{
	int	j;
	int	mult;
	int	total;
	int	num;
	int	*tab;
	int	*sorted;
	int	hold_fst;
	int	hold_snd;

	mult = 1;
	num = 5; // numero de numeros en un chunk
	total = ft_lstsize(stack_A);
	sorted = sorted_array(stack_to_array(stack_A), ft_lstsize(stack_A));
	while (stack_A != NULL)
	{
		while (ft_lstsize(stack_A) > (total - num * mult)
			&& ft_lstsize(stack_A) != 0)
		{
			tab = stack_to_array(stack_A);
			hold_fst = upwards(tab, sorted, num * mult, ft_lstsize(stack_A));
			hold_snd = downwards(tab, sorted, num * mult, ft_lstsize(stack_A));
			j = 0;
			if (hold_fst <= (ft_lstsize(stack_A) - hold_snd - 1))
			{
				while (j++ < hold_fst)
					rotate(&stack_A, 'A');
				push(&stack_A, &stack_B, 'A');
			}
			else
			{
				while (j++ < ft_lstsize(stack_A) - hold_snd)
					rrotate(&stack_A, 'A');
				push(&stack_A, &stack_B, 'A');
			}
			printf("B ");
			print_list(stack_B);
			printf("A ");
			print_list(stack_A);
		}
		mult++;
		getchar();
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*list_A;
	t_list	*list_B;
	int		*nums;

	i = 0;
	//tiene que poder recibir string
	nums = array_number(argc, argv);
	list_A = create_list(argc, nums);
	print_list(list_A);
	list_B = NULL;
	sort(list_A, list_B);
	//cuidadito con el cero
}
