/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:36:05 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/03/22 13:19:36 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
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
	list_1 = create_list(argc, nums);
	list_2 = create_list(argc, nums);
	printf("swap\n");
	print_list(list_s);
	swap(list_s);
	print_list(list_s);
	printf("push\n");
	//printf("push_1\n");
	//print_list(list_1);
	//printf("push_2\n");
	//print_list(list_2);
	push(&list_2, &list_1);
	printf("push_1\n");
	print_list(list_1);
	printf("push_2\n");
	print_list(list_2);
	//print_list(list);

	printf("rotate\n");
	print_list(list_r);
	rotate(&list_r);
	print_list(list_r);

	printf("rrotate\n");
	print_list(list_rr);
	rrotate(&list_rr);
	print_list(list_rr);
}
