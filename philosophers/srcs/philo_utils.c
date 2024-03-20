/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:36:08 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/20 18:10:57 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	msg_error(char *message)
{
	printf("%s\n", message);
	return (1);
}

int	ft_time(void)
{
	struct timeval	e;

	gettimeofday(&e, 0);
	return (e.tv_sec * 1000 + e.tv_usec / 1000);
}

int	ft_usleep(int time)
{
	int	start;

	start = ft_time();
	while ((ft_time() - start) < time)
		usleep(time / 10);
	return (0);
}

int	checker(int argc, char **argv)
{
	if (argc < 5 || argc > 7)
		return (msg_error("El nº de argumentos introducidos no es correcto."));
	else if (ft_atoi(argv[1]) < 1)
		return (msg_error("El nº de filósofos no puede ser inferior a 1."));
	else if (ft_atoi(argv[1]) > 200)
		return (msg_error("El nº de filósofos no debe ser superior a 200."));
	else if (ft_atoi(argv[2]) < 0)
		return (msg_error("El time_to_die no puede ser negativo."));
	else if (ft_atoi(argv[3]) < 0)
		return (msg_error("El time_to_eat no puede ser negativo."));
	else if (ft_atoi(argv[4]) < 0)
		return (msg_error("El time_to_sleep no puede ser negativo."));
	else if (ft_atoi(argv[4]) < 0)
		return (msg_error("El nº de comidas debe ser mayor a 0."));
	else
		return (0);

}

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
