/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:00:37 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/28 20:01:49 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list **stack, char c)
{
	t_list	*aux;

	if (ft_lstsize(*stack) < 2)
		return ;
	aux = malloc(sizeof(t_list));
	aux->content = (*stack)->next->content;
	(*stack)->next->content = (*stack)->content;
	(*stack)->content = aux->content;
	free(aux);
	if (c == 'A')
		write(1, "sa\n", 3);
	else if (c == 'B')
		write(1, "sb\n", 3);
}

void	swap_all(t_list **stack_1, t_list **stack_2)
{
	swap(stack_1, 'C');
	swap(stack_2, 'C');
	write(1, "ss\n", 3);
}

/*toma el primer elemento del stack 1 y lo pone encima 
del stack 2. No hace nada si 1 está vacío.*/
void	push(t_list **stack_1, t_list **stack_2, char c)
{
	t_list	*aux;

	if (ft_lstsize(*stack_1) < 1)
		return ;
	if (*stack_2 == NULL)
	{
		aux = *stack_1;
		*stack_2 = aux;
		*stack_1 = (*stack_1)->next;
		(*stack_2)->next = NULL;
	}
	else
	{
		aux = *stack_2;
		*stack_2 = *stack_1;
		*stack_1 = (*stack_1)->next;
		(*stack_2)->next = aux;
	}
	if (c == 'A')
		write(1, "pa\n", 3);
	else if (c == 'B')
		write(1, "pb\n", 3);
}

void	rotate(t_list **stack, char c)
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
	if (c == 'A')
		write(1, "ra\n", 3);
	else if (c == 'B')
		write(1, "rb\n", 3);
}

void	rrotate(t_list **stack, char c)
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
	if (c == 'A')
		write(1, "rra\n", 4);
	else if (c == 'B')
		write(1, "rrb\n", 4);
}
