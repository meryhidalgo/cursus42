/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:56:31 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/02 12:56:42 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_list(t_list *numbers)
{
	while (numbers)
	{
		printf("%d —> ", numbers->content);
		numbers = numbers->next;
	}
	printf("NULL\n");
}

void	print_array(int *tab, int length)
{
	int	i;

	i = 0;
	while (i < length)
		printf("%d ", tab[i++]);
	printf("\n");
}
