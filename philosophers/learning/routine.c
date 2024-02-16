
void* routine(void *philo)
{
	//struct timeval s;
	struct timeval e;
	t_philo *p = (t_philo*) philo;
	
	while ((*p).status != 3)
	{
		if ((*p).l_fork == 0 && (*p).r_fork == 0 && (*p).status != 0) //y que ya ha dormido
		{
			pthread_mutex_lock(&r_mutex);
			pthread_mutex_lock(&l_mutex);
			*((*p).r_fork) = 1;
			(*p).l_fork = 1;
			(*p).status = 0;
			gettimeofday(&e, 0);
			printf("Philo %i is eating %d \n", (*p).id, e.tv_usec);
			usleep((*p).time_to_eat);
			*((*p).r_fork) = 0;
			(*p).l_fork = 0;
			gettimeofday(&e, 0);
			(*p).last_eating = e.tv_usec;
			pthread_mutex_unlock(&r_mutex);
			pthread_mutex_unlock(&l_mutex);
			(*p).status = 1;
			printf("Philo %i is sleeping %d \n", (*p).id, e.tv_usec);
			usleep((*p).time_to_sleep);
		}
		else if ((*p).status == 1)
		{
			gettimeofday(&e, 0);
			printf("Philo %i is thinking %d \n", (*p).id, e.tv_usec);
		}
	}
	printf("Philo %i is dead", (*p).id);
	exit(0); //???????
	return (NULL); // or data
}


void* thread_run(void *philo)
{
	struct timeval s;
	struct timeval e;
	t_philo *p = (t_philo*) philo;
	
	if ((*p).l_fork == 0 && (*p).r_fork == 0) //y que ya ha dormido
	{
		*((*p).r_fork) = 1;
		(*p).l_fork = 1;
		pthread_mutex_lock(&r_mutex);
		*((*p).r_fork) = 0;
		pthread_mutex_unlock(&r_mutex);
		pthread_mutex_lock(&l_mutex);
		(*p).l_fork = 0;
		pthread_mutex_unlock(&l_mutex);
	}
	gettimeofday(&s, 0);
	//printf("Philo %i goes to sleep at time %ld \n", (*p).id, s.tv_sec * 1000000 + s.tv_usec);
	printf("Philo %i goes to sleep at time %d \n", (*p).id, s.tv_usec);
	usleep((*p).time_to_sleep);
	gettimeofday(&e, 0);
	//printf("Philo %i wakes up at time %ld \n", (*p).id, s.tv_sec * 1000000 + s.tv_usec);
	printf("Philo %i wakes up %d \n", (*p).id, e.tv_usec);
	return (NULL); // or data
}
