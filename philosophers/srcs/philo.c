/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:21:23 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/26 16:47:58 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_philo(t_philo *philos, char **argv, long int ini, t_program *program)
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
		philos[i].nb_meals = 0;
		philos[i].last_eating = ini;
		philos[i].ini = ini;
		philos[i].program = program;
		if (pthread_mutex_init(&philos[i].l_fork, NULL) != 0)
			return (-1);
		if (i > 0)
			philos[i].r_fork = &(philos[i - 1].l_fork);
		if (pthread_mutex_init(&philos[i].monitor, NULL) != 0)
			return (-1);
		i++;
	}
	philos[0].r_fork = &(philos[i - 1].l_fork);
	return (0);
}

int	ft_continue(t_program program)
{
	int	d;
	int	e;

	pthread_mutex_lock(&program.mwrite);
	d = program.death_ph;
	pthread_mutex_unlock(&program.mwrite);
	pthread_mutex_lock(&program.ewrite);
	e = program.eaten_ph;
	pthread_mutex_unlock(&program.ewrite);
	if (d != 0 || e != 0)
		return (1);
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	if (p->id % 2 == 0)
		ft_usleep(1);
	while (check_death(p) == 0) //while (1)
	{
		if (ft_continue(*p->program) == 1 || eat(p) == 1)
			return (philo);
		if (ft_continue(*p->program) == 0)
			fsleep(p);
		if (ft_continue(*p->program) == 0)
			think(p);
		if (ft_continue(*p->program) == 1)
			return (philo);
		//printf("%i %d eaten status\n", p->id, p->program->eaten_ph);
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
	program.death_ph = 0;
	program.eaten_ph = 0;
	if (argc > 5)
		program.nb_meals = ft_atoi(argv[5]);
	else
		program.nb_meals = -1;
	if (pthread_mutex_init(&program.mwrite, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&program.ewrite, NULL) != 0)
		return (-1);
	philos = (t_philo *)malloc(sizeof(t_philo) * program.nb_philo);
	init_philo(philos, argv, ini.tv_sec * 1000 + ini.tv_usec / 1000, &program);
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
		if (philo_death(philos, &program) == 1)
		{
			//system("leaks -q philo");
			printf("MUERTE");
			return (0);
		}
		if (program.nb_meals > 0 && check_eaten(philos, &program, 0) == 1)
		{
			end_program(philos, &program);
			//system("leaks -q philo");
			printf("FIN COMIDAS");
			return (0);
		}
	}
}

//falla al aumentar el número de filósofos
//entiendo que habría que aumentar el tiempo de los pares para que complete el bucle


//sin -fsanitize=thread -g parece que funciona ok pero falla con muchos filos
// con la flag no da fallos pero imprime las siestas y pensamientos de los filos despues de morir uno

//me falta arreglar que pasa si el filosofo muere antes de empezar a comer
//porque sean muy tardones el resto
//el bucle de while(1) no considera que pueda pasar

//un filo solo un tenedor !!!!
