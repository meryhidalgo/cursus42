/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:21:43 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/10/13 19:31:41 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>

static int	nb_percentage(char const *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 1;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%')
			nb++;
		i++;
	}
	return (nb);
}

int	ft_printf(char const *s, ...)
{
	va_list	ap;

	va_start(ap, nb_percentage(s));
	
}
