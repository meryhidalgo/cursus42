/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:35:01 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/03/22 17:48:37 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list *stack_A, t_list *stack_B)
{
	int	i;
	int	num;
	int	qui;
	int	*tab;

	i = 0;
	qui = 0;
	num = 20;
	tab = stack_to_array(stack_A);
	sorted_array(&tab, ft_lstsize(stack_A));
	while (stack_A)
	{
		qui = 0;
		while (i < num)
		{
			if (stack_A->content == tab[i])
			{
				push(&stack_B, &stack_A);
				qui = 1;
				break ;
			}
			i++;
		}
			getchar();
		if (qui == 0)
			rotate(&stack_A);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*list_A;
	t_list	*list_B;
	int		*nums;

	i = 0;
	nums = array_number(argc, argv);
	list_A = create_list(argc, nums);
	list_B = NULL;
	sort(list_A, list_B);
	printf("A\n");
	print_list(list_A);
	printf("B\n");
	print_list(list_B);
}
