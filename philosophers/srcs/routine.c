/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:37:51 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/26 16:49:08 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	eat(t_philo *p) //cuadran lineas sin comentarios
{
	struct timeval	e;

	pthread_mutex_lock(p->r_fork);
	if (check_death(p) == 1)
	{
		pthread_mutex_unlock(p->r_fork);
		return (1);
	}
	printf("%d %i has taken a fork\n", (int)(ft_time() - p->ini), p->id);
	if (p->program->nb_philo == 1)
	{
		ft_usleep(p->time_to_die);
		return (1);
	}
	if (ft_continue(*p->program) == 1)
		return (1);
	pthread_mutex_lock(&p->l_fork);
	printf("%d %i has taken a fork\n", (int)(ft_time() - p->ini), p->id);
	p->status = 0;
	pthread_mutex_lock(&p->monitor);
	p->nb_meals++;
	gettimeofday(&e, 0);
	p->last_eating = e.tv_sec * 1000 + e.tv_usec / 1000;
	pthread_mutex_unlock(&p->monitor);
	if (ft_continue(*p->program) == 1)
		return (1);
	printf("%d %i is eating\n", (int)(ft_time() - p->ini), p->id);
	ft_usleep(p->time_to_eat);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(&p->l_fork);
	return (0);
}

void	fsleep(t_philo *p)
{
	p->status = 1;
	printf("%d %i is sleeping\n", (int)(ft_time() - p->ini), p->id);
	ft_usleep(p->time_to_sleep);
}

void	think(t_philo *p)
{
	p->status = 2;
	printf("%d %i is thinking\n", (int)(ft_time() - p->ini), p->id);
}
