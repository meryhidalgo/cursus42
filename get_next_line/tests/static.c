/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:33:04 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/01/24 11:46:04 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	valor(int x)
{
	return (x + 1);
}

int	fun(void)
{
	static int	count;

	count = 0;
	valor (count);
	return (count);
}

int	main(void)
{
	char	*s;

	s = "hola\n";
	printf("%d ", fun());
	printf("%d ", fun());
	printf("te saluda: %s y adiós", s);
	return (0);
}
