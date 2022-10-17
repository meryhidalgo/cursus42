/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_va.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:20 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/10/17 18:18:00 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int sum(int num_args, ...)
{
	int		val;
	va_list	ap;
	int		i;

	va_start(ap, num_args);
	i = 0;
	val = 0;
	while (i < num_args)
	{
		val += va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return val;
}

int main ()
{
	printf("Sum of 15 and 56 = %d\n", sum(2, 15, 56));
	return 0;
}
