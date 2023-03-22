/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:00:37 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/03/22 14:09:09 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	t_list	*aux;

	if (ft_lstsize(stack) < 2)
		return ;
	aux = malloc(sizeof(t_list));
	aux->content = stack->next->content;
	stack->next->content = stack->content;
	stack->content = aux->content;
	free(aux);
}

//toma el primer elemento del stack b (2) y lo pone encima del stack a (1). No hace nada si b(2) está vacío.
void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*aux;

	if (ft_lstsize(*stack_2) < 1)
		return ;
	aux = *stack_2;
	ft_lstadd_front(stack_1, aux);
	*stack_2 = (*stack_2)->next->next;
}

void	rotate(t_list **stack)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(*stack) < 1)
		return ;
	aux = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(aux);
	last->next = aux;
	last->next->next = NULL;
}

void	rrotate(t_list **stack)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(*stack) < 1)
		return ;
	
	aux = *stack;
	while (aux->next != NULL)
	{
		last = aux;
		aux = aux->next;
	}
	ft_lstadd_front(stack, aux);
	last->next = NULL;
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
