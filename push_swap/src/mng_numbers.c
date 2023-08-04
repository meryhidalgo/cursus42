/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:12:06 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/02 13:26:41 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*si p=1 es un string*/
int	*array_number(int argc, char **s_number, int p)
{
	int	i;
	int	j;
	int	*a_number;

	i = 1;
	j = 0;
	if (p == 1)
	{
		i = 0;
		if (s_number[0] == NULL)
			end_error();
		a_number = (int *)malloc(sizeof(int) * (argc));
	}
	else
		a_number = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		if (ft_isdigit(s_number[i]) == 0)
			end_error();
		a_number[j++] = ft_atoi(s_number[i++]);
	}
	return (a_number);
}

int	*stack_to_array(t_list *stack)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * (ft_lstsize(stack)));
	while (stack)
	{
		tab[i++] = stack->content;
		stack = stack->next;
	}
	return (tab);
}

t_list	*create_list(int len, int *a_number)
{
	t_list	*list;
	t_list	*node;
	int		i;

	list = ft_lstnew(a_number[0]);
	i = 1;
	while (i < len - 1)
	{
		node = ft_lstnew(a_number[i]);
		ft_lstadd_back(&list, node);
		i++;
	}
	return (list);
}

int	nb_chunks(int length)
{
	if (length < 20)
		return (5);
	else if (length < 50)
		return (10);
	else if (length < 100)
		return (20);
	else if (length < 1000)
		return (50);
	else if (length < 10000)
		return (100);
	else
		return (1000);
}

/*int	main(int argc, char **argv)
{
	t_list	*list_s;
	int		*nums;

	nums = array_number(argc, argv);
	print_array(nums);
	list_s = create_list(argc, nums);
	print_list(list_s);
}*/
