/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:07:57 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/04/12 12:22:44 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DIE 3
# define FORK 4

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	long int			ini;
	int					status;// 0 for eating, 1 for sleeping, 2 for thinking, 3 DEAD
	int					total_philos;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	long int			last_eating;
	int					meals_eaten;
	int					num_times_to_eat;
	int					*dead;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		dstatus; //protege dead
	pthread_mutex_t		mstatus; //protege meals_eaten
	pthread_mutex_t		stat; //protege status
	pthread_mutex_t		last; //protege last_eating
}				t_philo;

typedef struct s_program
{
	int					nb_philo;
	int					death_ph;
	t_philo				*philos;
}				t_program;

int		msg_error(char *message);
int		ft_atoi(const char *str);
int		checker(int argc, char **argv);
int		ft_usleep(int time);
int		ft_time(void);
int		init_philo(int argc, t_philo *philos, char **argv, long int ini, t_program program);
int		init_program(int argc, char **argv, t_program *program);
void	eat(t_philo *p);
void	fsleep(t_philo *p);
void	think(t_philo *p);
int		ft_continue(t_philo *philo);
int		check_death(t_philo *p);
int		check_eaten(t_philo *philos, t_program *program);
int		philo_death(t_philo *philos, t_program *program);
int		end_program(t_philo *philos, t_program program);

#endif