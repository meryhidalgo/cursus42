/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:55:37 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/04/12 13:40:11 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_argv(int argc, char **argv, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].total_philos = ft_atoi(argv[1]);
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc > 5)
			philos[i].num_times_to_eat = ft_atoi(argv[5]);
		else
			philos[i].num_times_to_eat = -1;
		i++;
	}
}

int	init_philo(t_philo *philos, long int ini, t_program program)
{
	int	i;

	i = 0;
	while (i < program.nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].status = -1;
		philos[i].meals_eaten = 0;
		philos[i].last_eating = ini;
		philos[i].ini = ini;
		philos[i].dead = &program.death_ph;
		if (pthread_mutex_init(&philos[i].l_fork, NULL) != 0)
			return (msg_error("Error in initiating mutex."));
		if (i > 0)
			philos[i].r_fork = &(philos[i - 1].l_fork);
		philos[i].dstatus = &program.dcontrol;
		if (pthread_mutex_init(&philos[i].mstatus, NULL) != 0
			|| pthread_mutex_init(&philos[i].stat, NULL) != 0
			|| pthread_mutex_init(&philos[i].last, NULL) != 0)
			return (msg_error("Error in initiating mutex."));
		i++;
	}
	philos[0].r_fork = &(philos[i - 1].l_fork);
	return (0);
}

int	init_program(int argc, char **argv, t_program *program)
{
	if (checker(argc, argv) == 1)
		return (1);
	program->nb_philo = ft_atoi(argv[1]);
	program->death_ph = 0;
	if (pthread_mutex_init(&program->dcontrol, NULL) != 0)
		return (msg_error("Error in initiating mutex."));
	return (0);
}
