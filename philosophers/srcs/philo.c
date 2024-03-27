/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:21:23 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/27 12:54:11 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
	/*if (p->id % 2 == 0)
		ft_usleep(1);*/
	while (ft_continue(*p->program) == 0) //while (1)
	{
		if (eat(p) == 1)
			return (philo);
		fsleep(p);
		think(p);
	}
	return (philo);
}

void	*supervisor(void *data)
{
	t_philo	*philos;

	philos = (t_philo *) data;
	while (1)
	{
		if (philo_death(philos, philos[0].program) == 1)
		{
			//system("leaks -q philo");
			printf("MUERTE");
			return (0);
		}
		if (philos[0].program->nb_meals > 0 && check_eaten(philos, philos[0].program, 0) == 1)
		{
			end_program(philos, philos[0].program);
			//system("leaks -q philo");
			printf("FIN COMIDAS");
			return (0);
		}
	}
}

int	main(int argc, char **argv)
{
	int				i;
	t_philo			*philos;
	t_program		program;
	//pthread_t		thread;
	struct timeval	ini;

	gettimeofday(&ini, 0);
	if (init_program(argc, argv, &program) < 0)
		return (-1);
	philos = (t_philo *)malloc(sizeof(t_philo) * program.nb_philo);
	init_philo(philos, argv, ini.tv_sec * 1000 + ini.tv_usec / 1000, &program);
	/*if (pthread_create(&thread, NULL, supervisor, &philos) != 0)
	{
		printf("Error creating the thread");
		return (-1);
	}*/
	i = 0;
	while (i < program.nb_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
			return (msg_error("Error creating the thread"));
		i++;
	}
	while (1)
	{
		if ((program.nb_meals > 0 && check_eaten(philos, &program, 0) == 1)
			|| (philo_death(philos, &program) == 1))
		{
			end_program(philos, &program);
			//system("leaks -q philo");
			//printf("FIN");
			return (0);
		}
		/*if (philo_death(philos, &program) == 1)
		{
			//system("leaks -q philo");
			printf("MUERTE");
			return (0);
		}*/
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
