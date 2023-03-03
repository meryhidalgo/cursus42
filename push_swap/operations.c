/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:00:37 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/03/03 17:14:54 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	t_list	*aux;

	aux = malloc(sizeof(t_list));
	if (ft_lstsize(stack) < 2)
		return ;
	aux->content = stack->next->content;
	stack->next->content = stack->content;
	stack->content = aux->content;
}

int	*array_number(int argc, char **s_number)
{
	int	i;
	int	*a_number;

	i = 1;
	a_number = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		a_number[i] = ft_atoi(s_number[i]);
		i++;
	}
	return (a_number);
}

t_list	*create_list(int len, int *a_number)
{
	t_list	*list;
	t_list	*node;
	int		i;

	list = ft_lstnew(a_number[1]);
	i = 2;
	while (i < len)
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

int	main(int argc, char **argv)
{
	int		i;
	t_list	*list;
	int		*nums;

	i = 0;
	nums = array_number(argc, argv);
	list = create_list(argc, nums);
	print_list(list);
	swap(list);
	print_list(list);
}
