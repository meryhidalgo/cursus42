/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:54:30 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/29 17:33:57 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while ((*lst) != NULL)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = aux;
	}
}
