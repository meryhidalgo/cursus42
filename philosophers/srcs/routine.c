/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:37:51 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/27 13:02:24 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	display_message(int action, t_program program, long int ini, int id)
{
	//printf("eaten %d\n\n", program.eaten_ph);
	//printf("death %d\n\n", program.death_ph);
	if (ft_continue(program) == 0)
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
		return (0);
	}
	else
		return (1);
}

int	eat(t_philo *p) //cuadran lineas sin comentarios
{
	struct timeval	e;

	if (p->id % 2 == 0)
		pthread_mutex_lock(p->r_fork);
	else
		pthread_mutex_lock(&p->l_fork);
	if (display_message(FORK, *p->program, p->ini, p->id) == 1)
		return (1);
	if (p->program->nb_philo == 1)
	{
		ft_usleep(p->time_to_die);
		return (1);
	}
	if (p->id % 2 == 0)
		pthread_mutex_lock(&p->l_fork);
	else
		pthread_mutex_lock(p->r_fork);
	if (display_message(FORK, *p->program, p->ini, p->id) == 1)
		return (1);
	pthread_mutex_lock(&p->monitor);
	p->nb_meals++;
	gettimeofday(&e, 0);
	p->last_eating = e.tv_sec * 1000 + e.tv_usec / 1000;
	if (display_message(EAT, *p->program, p->ini, p->id) == 1)
		return (1);
	ft_usleep(p->time_to_eat);
	pthread_mutex_unlock(&p->monitor);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(&p->l_fork);
	return (0);
}

void	fsleep(t_philo *p)
{
	display_message(SLEEP, *p->program, p->ini, p->id);
	ft_usleep(p->time_to_sleep);
}

void	think(t_philo *p)
{
	display_message(THINK, *p->program, p->ini, p->id);
}

