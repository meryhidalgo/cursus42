/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:36:08 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/27 13:00:36 by mcarazo-         ###   ########.fr       */
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

int	end_program(t_philo *philos, t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nb_philo)
	{
		pthread_detach(philos[i].thread);
		pthread_mutex_destroy(philos[i].r_fork);
		pthread_mutex_destroy(&philos[i].monitor);
		pthread_mutex_destroy(&philos[i].mstatus);
		i++;
	}
	pthread_mutex_destroy(&program->mwrite);
	free(philos);
	return (1);
}

