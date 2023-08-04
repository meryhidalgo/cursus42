/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:40:56 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/02 14:02:00 by mcarazo-         ###   ########.fr       */
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

int		ft_isdigit(char *c);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
int		nb_chunks(int length);
char	**ft_split(char const *s, char c);
int		countwords(char const *s, char c);
t_list	*ft_lstnew(int content);
int		end_error(void);
void	print_array(int *tab, int length);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_issorted(t_list **stack_A, int *tab, int total);
void	swap(t_list **stack, char c);
void	push(t_list **stack_1, t_list **stack_2, char c);
void	rotate(t_list **stack, char c);
void	rrotate(t_list **stack, char c);
int		*array_number(int argc, char **s_number, int p);
t_list	*create_list(int len, int *a_number);
void	print_list(t_list *numbers);
int		upwards(int *tab, int *sorted, int range[2], int length);
int		downwards(int *tab, int *sorted, int range[2], int length);
int		*stack_to_array(t_list *stack);
int		*sorted_array(int *tab, int size);
int		*trunc_sorted(int *sorted, int size);
void	push_swap(t_list **stack_A, t_list **stack_B);
void	sort_three(t_list **stack_A);

#endif
