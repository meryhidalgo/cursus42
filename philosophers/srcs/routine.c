/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:37:51 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/04/12 12:22:59 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	display_message(int action, t_philo *philo, long int ini, int id)
{
	//printf("eaten %d\n\n", program.eaten_ph);
	//printf("death %d\n\n", program.death_ph);
	//writelock??????
	if (ft_continue(philo) == 0)
	{
		if (action == EAT)
			printf("%d %i is eating\n", (int)(ft_time() - ini), id);
		else if (action == SLEEP)
			printf("%d %i is sleeping\n", (int)(ft_time() - ini), id);
		else if (action == THINK)
			printf("%d %i is thinking\n", (int)(ft_time() - ini), id);
		else if (action == DIE)
			printf("%d %i died\n", (int)(ft_time() - ini), id);
		else if (action == FORK)
			printf("%d %i has taken a fork\n", (int)(ft_time() - ini), id);
	}
}

int	eat2(t_philo *p) //cuadran lineas sin comentarios
{
	struct timeval	e;

	if (p->id % 2 == 0)
		pthread_mutex_lock(p->r_fork);
	else
		pthread_mutex_lock(&p->l_fork);
	//if (display_message(FORK, p, p->ini, p->id) == 1)
	//	return (1);
	display_message(FORK, p, p->ini, p->id);
	if (p->id % 2 == 0)
		pthread_mutex_lock(&p->l_fork);
	else
		pthread_mutex_lock(p->r_fork);
	display_message(FORK, p, p->ini, p->id);
	//if (display_message(FORK, p, p->ini, p->id) == 1)
	//	return (1);
	pthread_mutex_lock(&p->mstatus);
	p->meals_eaten++;
	pthread_mutex_unlock(&p->mstatus);
	gettimeofday(&e, 0);
	pthread_mutex_lock(&p->last);
	p->last_eating = e.tv_sec * 1000 + e.tv_usec / 1000;
	//if (display_message(EAT, p, p->ini, p->id) == 1)
	//	return (1);
	display_message(EAT, p, p->ini, p->id);
	pthread_mutex_unlock(&p->last); //tal vez antes de display EAT
	pthread_mutex_lock(&p->stat);
	p->status = EAT;
	pthread_mutex_unlock(&p->stat);
	ft_usleep(p->time_to_eat);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(&p->l_fork);
	return (0);
}

void	eat(t_philo *p) //cuadran lineas sin comentarios
{
	struct timeval	e;

	pthread_mutex_lock(p->r_fork);
	display_message(FORK, p, p->ini, p->id);
	if (p->total_philos == 1)
	{
		ft_usleep(p->time_to_die);
		pthread_mutex_unlock(p->r_fork);
		return ;
	}
	pthread_mutex_lock(&p->l_fork);
	display_message(FORK, p, p->ini, p->id);
	pthread_mutex_lock(&p->mstatus);
	p->meals_eaten++;
	pthread_mutex_unlock(&p->mstatus);
	gettimeofday(&e, 0);
	pthread_mutex_lock(&p->last);
	p->last_eating = e.tv_sec * 1000 + e.tv_usec / 1000;
	//if (display_message(EAT, p, p->ini, p->id) == 1)
	//	return (1);
	display_message(EAT, p, p->ini, p->id);
	pthread_mutex_unlock(&p->last); //tal vez antes de display EAT
	pthread_mutex_lock(&p->stat);
	p->status = EAT;
	pthread_mutex_unlock(&p->stat);
	ft_usleep(p->time_to_eat);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(&p->l_fork);
}


void	fsleep(t_philo *p)
{
	pthread_mutex_lock(&p->stat);
	p->status = SLEEP;
	pthread_mutex_unlock(&p->stat);
	display_message(SLEEP, p, p->ini, p->id);
	ft_usleep(p->time_to_sleep);
}

void	think(t_philo *p)
{
	pthread_mutex_lock(&p->stat);
	p->status = THINK;
	pthread_mutex_unlock(&p->stat);
	display_message(THINK, p, p->ini, p->id);
}

