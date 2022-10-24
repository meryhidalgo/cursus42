/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:11:54 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/10/24 19:47:01 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nb_digit(long n, int sub)
{
	int	i;

	if (n < 0)
		i = 2;
	else 
		i = 1;
	while (n / sub != 0)
	{
		i++;
		n = n / sub;
	}
	return (i);
}

int	ft_print_address(void *p)
{
	long	n;
	long	rem;
	char	addr[10];
	int		i;
	int		t;

	n =(long) p;
	i = 9;
	t = 2;
	addr[9] = 0;
	if (n == 0)
		addr[--i] = '0';
	while (n != 0)
	{
		--i;
		rem = n % 16;
		if (rem > 9)
			addr[i] = 87 + rem;
		else
			addr[i] = 48 + rem;
		n = n / 16;
	}
	write(1, "0x", 2);
	while (addr[i])
	{
		write(1, &addr[i], 1);
		i++;
		t++;
	}
	return (t);
}

int	ft_putnbr_hex(long n, char *c)
{
	if (n < 0)
	{
		n = UINT_MAX + n + 1;
	}
	if (n != 0)
	{
		ft_putnbr_hex(n / 16, c);
		write(1, &c[n % 16], 1);
	}
	return (nb_digit(n, 16));
}

/*int	main()
{
	void	*p;

	//ft_print_address(p);
	//printf("%d\n", printf("%p\n", p));
	//printf("%u\n", -34);
	printf("\n%d\n", ft_putnbr_hex(-10, "0123456789abcdef"));
	printf("PRINT ORIGINAL %x\n", -10);
	printf("%d\n", UINT_MAX);
	printf("%%");
}*/
