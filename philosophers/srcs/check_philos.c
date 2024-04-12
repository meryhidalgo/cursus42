/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:49:04 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/04/12 13:12:17 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	checker(int argc, char **argv)
{
	if (argc < 5 || argc > 7)
		return (msg_error("El nº de argumentos introducidos no es correcto."));
	else if (ft_atoi(argv[1]) < 1 || arg_content(argv[1]) < 0)
		return (msg_error("El nº de filósofos es inválido"));
	else if (ft_atoi(argv[1]) > 200 || arg_content(argv[1]) < 0)
		return (msg_error("El nº de filósofos es inválido"));
	else if (ft_atoi(argv[2]) < 0 || arg_content(argv[2]) < 0)
		return (msg_error("El time_to_die es inválido"));
	else if (ft_atoi(argv[3]) < 0 || arg_content(argv[3]) < 0)
		return (msg_error("El time_to_eat es inválido"));
	else if (ft_atoi(argv[4]) < 0 || arg_content(argv[4]) < 0)
		return (msg_error("El time_to_sleep es inválido"));
	else if (argc > 5 && (ft_atoi(argv[5]) < 0 || arg_content(argv[5]) < 0))
		return (msg_error("El nº de comidas es inválido, debe ser mayor a 0."));
	return (0);
}

int	check_eaten(t_philo *philos, t_program *program)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	if (philos->num_times_to_eat < 0)
		return (0);
	while (i < program->nb_philo)
	{
		pthread_mutex_lock(&philos[i].mstatus);
		if (philos[i].meals_eaten >= philos->num_times_to_eat)
			finished++;
		pthread_mutex_unlock(&philos[i].mstatus);
		i++;
	}
	if (finished == program->nb_philo)
	{
		pthread_mutex_lock(philos[0].dstatus);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dstatus);
		return (1);
	}
	return (0);
}

int	check_death(t_philo *p)
{
	struct timeval	t;
	long int		now;

	gettimeofday(&t, 0);
	now = t.tv_sec * 1000 + t.tv_usec / 1000;
	pthread_mutex_lock(&p->last);
	pthread_mutex_lock(&p->stat);
	if (now - p->last_eating > p->time_to_die && p->status != 0)
	{
		pthread_mutex_lock(p->dstatus);
		*p->dead = 1;
		pthread_mutex_unlock(p->dstatus);
		pthread_mutex_unlock(&p->stat);
		return (pthread_mutex_unlock(&p->last), 1);
	}
	pthread_mutex_unlock(&p->last);
	pthread_mutex_unlock(&p->stat);
	return (0);
}

int	philo_death(t_philo *philos, t_program *program)
{
	int				i;
	struct timeval	t;
	long int		now;
	int				id;

	i = 0;
	while (i < program->nb_philo)
	{
		gettimeofday(&t, 0);
		now = t.tv_sec * 1000 + t.tv_usec / 1000;
		if (check_death(&philos[i]) == 1)
		{
			id = philos[i].id;
			printf("%d %i died\n", (int)(ft_time() - philos[i].ini), id);
			return (1);
		}
		i++;
	}
	return (0);
}
