/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:07:57 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/04/12 13:40:16 by mcarazo-         ###   ########.fr       */
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
	pthread_mutex_t		stat;
	int					status;
	int					total_philos;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	pthread_mutex_t		last;
	long int			last_eating;
	pthread_mutex_t		mstatus;
	int					meals_eaten;
	int					num_times_to_eat;
	pthread_mutex_t		*dstatus;
	int					*dead;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		l_fork;
}				t_philo;

typedef struct s_program
{
	int					nb_philo;
	int					death_ph;
	t_philo				*philos;
	pthread_mutex_t		dcontrol;
}				t_program;

int		msg_error(char *message);
int		ft_atoi(const char *str);
int		checker(int argc, char **argv);
int		ft_usleep(int time);
int		ft_time(void);
void	init_argv(int argc, char **argv, t_philo *philos);
int		init_philo(t_philo *philos, long int ini, t_program program);
int		init_program(int argc, char **argv, t_program *program);
void	display_message(int action, t_philo *philo, long int ini, int id);
void	eat(t_philo *p);
void	fsleep(t_philo *p);
void	think(t_philo *p);
int		ft_continue(t_philo *philo);
int		check_eaten(t_philo *philos, t_program *program);
int		philo_death(t_philo *philos, t_program *program);
int		end_program(t_philo *philos, t_program program, char *message);

#endif
