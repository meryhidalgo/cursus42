/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:36:05 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/03 11:18:33 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main2(int argc, char **argv)
{
	int		i;
	t_list	*list_s;
	t_list	*list_r;
	t_list	*list_rr;
	t_list	*list_1;
	t_list	*list_2;
	int		*nums;

	i = 0;
	nums = array_number(argc, argv);
	list_s = create_list(argc, nums);
	list_r = create_list(argc, nums);
	list_rr = create_list(argc, nums);
	//list_1 = create_list(argc, nums);
	list_2 = create_list(argc, nums);

	printf("swap\n");
	print_list(list_s);
	swap(&list_s, 'A');
	print_list(list_s);
	
	printf("push\n");
	push(&list_2, &list_1, 'A');
	printf("push_1\n");
	print_list(list_1);
	printf("push_2\n");
	print_list(list_2);
	//print_list(list);

	printf("rotate\n");
	print_list(list_r);
	rotate(&list_r, 'A');
	print_list(list_r);

	printf("rrotate\n");
	print_list(list_rr);
	rrotate(&list_rr, 'A');
	print_list(list_rr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*nums;

	nums = array_number(argc, argv);
	stack_a = create_list(argc, nums);
	stack_b = create_list(argc, nums);
	//stack_b = NULL;

	printf("push\n");
	push(&stack_a, &stack_b, 'A');
	printf("push_1\n");
	print_list(stack_b);
	printf("push_2\n");
	print_list(stack_a);
	return (1);
}
