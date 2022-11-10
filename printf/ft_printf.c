/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:21:43 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/11/10 16:03:22 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	type_data(char type, va_list *ap)
{
	long	nb;
	char	*s;

	if (type == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), 1));
	else if (type == 'i' || type == 'd')
	{
		nb = va_arg(*ap, int);
		ft_putnbr_fd(nb, 1);
		return (nb_digit(nb, 10));
	}
	else if (type == 'u')
	{
		nb = va_arg(*ap, int);
		if (nb < 0)
			nb = UINT_MAX + nb + 1;
		ft_putnbr_fd(nb, 1);
		return (nb_digit(nb, 10));
	}
	else if (type == 's')
		return (ft_putstr_fd(s = va_arg(*ap, char *), 1));
	else if (type == 'p')
		return (ft_print_address(va_arg(*ap, void *)));
	else if (type == 'x')
		return (ft_putnbr_hex(va_arg(*ap, int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_putnbr_hex(va_arg(*ap, int), "0123456789ABCDEF"));
	else if (type == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	ap;
	int		i;
	int		total;

	va_start(ap, s);
	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			total += type_data(s[i + 1], &ap);
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			total++;
			i++;
		}
	}
	return (total);
}

/*int	main()
{
	ft_printf("%d\n",ft_printf("%u\n", -214748364));
	printf ("FUNCION ORIGINAL\n");
	printf("%d\n",printf("%u\n", -214748364));
}*/
