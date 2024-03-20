/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:07:57 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/20 18:11:12 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_program
{
	int					nb_philo;
	pthread_mutex_t		mwrite;
}				t_program;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	long int			ini;
	int					status;// 0 for eating, 1 for sleeping, 2 for thinking, 3 DEAD
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	long int			last_eating;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		l_fork;
	t_program			*program;
}				t_philo;

int			ft_atoi(const char *str);
int			checker(int argc, char **argv);
int			ft_usleep(int time);
int			ft_time(void);
void		eat(t_philo *p);
void		fsleep(t_philo *p);
void		think(t_philo *p);

#endif
