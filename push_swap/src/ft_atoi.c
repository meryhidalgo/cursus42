/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:52:12 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/04/28 20:01:39 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long int	sol;

	i = 0;
	neg = 1;
	sol = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg = neg * -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if (sol * neg > 2147483647)
			return (-1);
		if (sol * neg < -2147483648)
			return (0);
		sol = sol * 10 + (str[i] - 48);
		i++;
	}
	return (sol * neg);
}
