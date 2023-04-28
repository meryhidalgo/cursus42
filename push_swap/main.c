/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:54:38 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/28 20:02:16 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*list_A;
	t_list	*list_B;
	int		*nums;

	i = 0;
	//tiene que poder recibir string
	nums = array_number(argc, argv);
	print_array(nums, 8);
	list_A = create_list(argc, nums);
	list_B = NULL;
	printf("A ");
	print_list(list_A);
	printf("B ");
	print_list(list_B);
	push_swap(&list_A, &list_B);
	printf("A ");
	print_list(list_A);
	printf("B ");
	print_list(list_B);
	//system("leaks -q a.out");
}
