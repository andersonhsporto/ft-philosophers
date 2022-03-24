#include "philosophers.h"

void	fork_mutex_handler(t_thinker *list, int status);
void	lunchtime(t_thinker *list);
void	naptime(t_thinker *list);
void	reflection_time(t_thinker *list);

void	*routine(void *list)
{
	t_thinker	*temp;

	temp = (t_thinker *)list;
	temp->time_start = ms_timeofday();
	if (temp->odd == true)
		usleep(50);
	printf("start day\n");
	while (temp->loop && temp->status != dead)
	{
		fork_mutex_handler(list, get_fork);
		lunchtime(list);
		fork_mutex_handler(list, drop_fork);
		if (temp->nbr_snacks == temp->data->args.optional)
			break ;
		naptime(list);
		reflection_time(list);
	}
	temp->status = endgame;
	return (NULL);
}

void	fork_mutex_handler(t_thinker *list, int status)
{
	if (status == get_fork)
	{
		pthread_mutex_lock(&list->is_dead);
		pthread_mutex_lock(&list->prev->fork);
		printf("%ld    %d   %s\n", (ms_timeofday() - list->time_start), \
			list->index, FORK);
		pthread_mutex_unlock(&list->is_dead);
		pthread_mutex_lock(&list->fork);
		printf("%ld    %d   %s\n", (ms_timeofday() - list->time_start), \
			list->index, FORK);
		pthread_mutex_unlock(&list->is_dead);
	}
	else
	{
		pthread_mutex_unlock(&list->prev->fork);
		pthread_mutex_unlock(&list->fork);
	}
	return ;
}

void	lunchtime(t_thinker *list)
{
	if (list->status != dead)
	{
		pthread_mutex_lock(&list->is_dead);
		printf("%ld    %d   %s\n", (ms_timeofday() - list->time_start), \
			list->index, EAT);
		list->status = eating;
		list->nbr_snacks++;
		list->last_meal = ms_timeofday();
		pthread_mutex_unlock(&list->is_dead);
		waiting(list->data->args.time_eat);
	}
	return ;
}

void	naptime(t_thinker *list)
{
	if (list->status != dead)
	{
		pthread_mutex_lock(&list->is_dead);
		printf("%ld    %d   %s\n", (ms_timeofday() - list->time_start), \
			list->index, SLEEP);
		list->status = rest;
		waiting(list->data->args.time_sleep);
		pthread_mutex_unlock(&list->is_dead);
	}
	return ;
}

void	reflection_time(t_thinker *list)
{
	if (list->status != dead)
	{
		pthread_mutex_lock(&list->is_dead);
		printf("%ld    %d   %s\n", (ms_timeofday() - list->time_start), \
			list->index, THINK);
		list->status = reflection;
		pthread_mutex_unlock(&list->is_dead);
	}
	return ;
}
