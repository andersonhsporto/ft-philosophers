/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_threads_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:08:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 12:55:19 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fork_mutex_handler(t_thinker *list, int status);
void	lunchtime(t_thinker *list);
void	naptime(t_thinker *list);
void	reflection_time(t_thinker *list);

void	*routine(void *list)
{
	t_thinker	*temp;

	temp = (t_thinker *)list;
	temp->time_start = ms_get_timeofday();
	if (temp->odd == true)
		usleep(50);
	printf("thread: %d foi inicializado!\n", temp->index);
	while (true)
	{
		fork_mutex_handler(list, get_fork);
		lunchtime(list);
		fork_mutex_handler(list, drop_fork);
		if (temp->nbr_snacks == temp->data->args.optional)
			break ;
		naptime(list);
		reflection_time(list);
	}
	return (NULL);
}

void	fork_mutex_handler(t_thinker *list, int status)
{
	if (status == get_fork)
	{
		pthread_mutex_lock(&list->prev->fork);
		printf("%ld    %d   %s\n", (ms_get_timeofday() - list->time_start), \
		list->index, FORK);
		pthread_mutex_lock(&list->fork);
		printf("%ld    %d   %s\n", (ms_get_timeofday() - list->time_start), \
		list->index, FORK);
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
	printf("%ld    %d   %s\n", (ms_get_timeofday() - list->time_start), \
		list->index, EAT);
	list->status = eating;
	list->nbr_snacks++;
	waiting(list->data->args.time_eat);
	return ;
}

void	naptime(t_thinker *list)
{
	printf("%ld    %d   %s\n", (ms_get_timeofday() - list->time_start), \
		list->index, SLEEP);
	list->status = rest;
	waiting(list->data->args.time_sleep);
	return ;
}

void	reflection_time(t_thinker *list)
{
	printf("%ld    %d   %s\n", (ms_get_timeofday() - list->time_start), \
		list->index, THINK);
	list->status = reflection;
	return ;
}