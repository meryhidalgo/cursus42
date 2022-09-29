/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:37:55 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/29 20:03:14 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_result;
	t_list	*aux;

	lst_result = NULL;
	while (lst != NULL)
	{
		aux = ft_lstnew(f(lst->content));
		if (aux == 0)
		{
			ft_lstclear(&lst_result, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_result, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (lst_result);
}

/*Itera la lista ’lst’ y aplica la función ’f’ al
contenido de cada nodo. Crea una lista resultante
de la aplicación correcta y sucesiva de la función
’f’ sobre cada nodo. La función ’del’ se utiliza
para eliminar el contenido de un nodo, si hace
falta.*/

			/*aux = lst->next;
			del(lst->content);
			free(lst);
			lst = aux;*/
