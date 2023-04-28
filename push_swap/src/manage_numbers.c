/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:12:06 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/28 20:04:08 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_array(int *tab, int length)
{
	int	i;

	i = 0;
	while (i < length)
		printf("%d ", tab[i++]);
	printf("\n");
}

int	*array_number(int argc, char **s_number)
{
	int	i;
	int	*a_number;

	i = 1;
	a_number = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		a_number[i - 1] = ft_atoi(s_number[i]);
		i++;
	}
	return (a_number);
}

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

void	print_list(t_list *numbers)
{
	while (numbers)
	{
		printf("%d —> ", numbers->content);
		numbers = numbers->next;
	}
	printf("NULL\n");
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
