/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:01:44 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/24 19:28:29 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digits(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		i;
	int		j;

	j = 0;
	if (n < 0)
		j = 1;
	number = (char *)malloc(sizeof(char) * digits(n) + 1 + j);
	if (number == 0)
		return (NULL);
	i = digits(n) + (j - 1);
	number[digits(n) + j] = '\0';
	if (n < 0)
		number[0] = '-';
	else
		number[0] = 48;
	while (n != 0)
	{
		if (n % 10 < 0)
			number[i--] = - (n % 10) + 48;
		else
			number[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (number);
}
