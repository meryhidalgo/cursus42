/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:21:23 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/20 18:51:40 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_philo(t_philo *philos, char **argv, long int ini, t_program program)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].status = -1;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		philos[i].last_eating = ini;
		philos[i].ini = ini;
		philos[i].program = &program;
		if (pthread_mutex_init(&philos[i].l_fork, NULL) != 0)
			return (-1);
		if (i > 0)
			philos[i].r_fork = &(philos[i - 1].l_fork);
		i++;
	}
	philos[0].r_fork = &(philos[i - 1].l_fork);
	return (0);
}

int	check_death(t_philo *p)
{
	struct timeval	t;
	long int		now;

	gettimeofday(&t, 0);
	now = t.tv_sec * 1000 + t.tv_usec / 1000;
	//printf ("%ld %ld\n", now, p->last_eating);
	if (now - p->last_eating > p->time_to_die && p->status != 0)
		return (1);
	return (0);
}

int	philo_death(t_philo *philos, int nb_philo)
{
	int				i;
	struct timeval	t;
	long int		now;

	i = 0;
	while (i < nb_philo)
	{
		gettimeofday(&t, 0);
		now = t.tv_sec * 1000 + t.tv_usec / 1000;
		if (check_death(&philos[i]) == 1)
		{
			printf("Philo %i died", philos[i].id);
			i = 0;
			while (i < nb_philo)
			{
				pthread_mutex_destroy(&philos[i].l_fork);
				i++;
			}
			pthread_mutex_destroy(&philos[i - 1].program->mwrite);
			free(philos);
			return (1);
		}
	}
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	if (p->id % 2 == 0)
		ft_usleep(1);
	while (check_death(p) == 0)
	{
		eat(p);
		fsleep(p);
		think(p);
	}
	return (philo);
}

int	main(int argc, char **argv)
{
	int				i;
	t_philo			*philos;
	t_program		program;
	struct timeval	ini;

	gettimeofday(&ini, 0);
	if (checker(argc, argv) == 1)
		return (-1);
	program.nb_philo = ft_atoi(argv[1]);
	if (pthread_mutex_init(&program.mwrite, NULL) != 0)
		return (-1);
	philos = (t_philo *)malloc(sizeof(t_philo) * program.nb_philo);
	init_philo(philos, argv, ini.tv_sec * 1000 + ini.tv_usec / 1000, program);
	i = 0;
	while (i < program.nb_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
		{
			printf("Error creating the thread");
			return (-1);
		}
		i++;
	}
	while (1)
	{
		if (philo_death(philos, program.nb_philo) == 1)
			return (0);
	}
}


//me falta arreglar que pasa si el filosofo muere antes de empezar a comer 
//porque sean muy tardones el resto
//el bucle de while(1) no considera que pueda pasar

//falla al aumentar el número de filósofos
//entiendo que habría que aumentar el tiempo de los pares para que complete el bucle

//falta setear comidas fijas y que finalice la ejecución
