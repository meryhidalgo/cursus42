/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:21:43 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/10/17 20:03:49 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

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

char	type_data(char type, va_list *ap)
{
	if (type == 'c')
	{
		ft_putchar_fd(va_arg(*ap, char), 1);
		return (1);
	}
	else if (type == 'i')
	{
		ft_putnbr_fd(va_arg(*ap, int), 1);
		return (1);
	}
	else if (type == 's')
	{
		ft_putstr_fd(va_arg(*ap, char *), 1);
		return (1);
	}
}

int	ft_printf(char const *s, ...)
{
	va_list	ap;
	int		i;

	if (nb_percentage == 0)
	{
		ft_putstr_fd(s, 1);
		return (1);
	}
	va_start(ap, nb_percentage(s));
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			type_data(s[i + 1], &ap);
		i++;
	}
}
