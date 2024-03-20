/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:37:51 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/20 18:10:28 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eat(t_philo *p)
{
	struct timeval	e;

	pthread_mutex_lock(&p->program->mwrite);
	pthread_mutex_lock(p->r_fork);
	printf("%d %i has taken a fork\n", (int)(ft_time() - p->ini), p->id);
	pthread_mutex_lock(&p->l_fork);
	printf("%d %i has taken a fork\n", (int)(ft_time() - p->ini), p->id);
	p->status = 0;
	printf("%d %i is eating\n", (int)(ft_time() - p->ini), p->id);
	pthread_mutex_unlock(&p->program->mwrite);
	ft_usleep(p->time_to_eat);
	gettimeofday(&e, 0);
	p->last_eating = e.tv_sec * 1000 + e.tv_usec / 1000;
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(&p->l_fork);
}

void	fsleep(t_philo *p)
{
	p->status = 1;
	pthread_mutex_lock(&p->program->mwrite);
	printf("%d %i is sleeping\n", (int)(ft_time() - p->ini), p->id);
	pthread_mutex_unlock(&p->program->mwrite);
	ft_usleep(p->time_to_sleep);
}

void	think(t_philo *p)
{
	p->status = 2;
	pthread_mutex_lock(&p->program->mwrite);
	printf("%d %i is thinking\n", (int)(ft_time() - p->ini), p->id);
	pthread_mutex_unlock(&p->program->mwrite);
}
