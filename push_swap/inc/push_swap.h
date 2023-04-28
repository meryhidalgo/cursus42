/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:40:56 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/28 20:06:34 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
t_list	*ft_lstnew(int content);
void	print_array(int *tab, int length);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	swap(t_list **stack, char c);
void	push(t_list **stack_1, t_list **stack_2, char c);
void	rotate(t_list **stack, char c);
void	rrotate(t_list **stack, char c);
int		*array_number(int argc, char **s_number);
t_list	*create_list(int len, int *a_number);
void	print_list(t_list *numbers);
int		upwards(int *tab, int *sorted, int num, int length);
int		downwards(int *tab, int *sorted, int num, int length);
int		*stack_to_array(t_list *stack);
int		*sorted_array(int *tab, int size);
void	push_swap(t_list **stack_A, t_list **stack_B);
void	sort_three(t_list **stack_A, int *tab);

#endif
