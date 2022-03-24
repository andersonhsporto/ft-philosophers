/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2-threads_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:08:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 03:59:28 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	bedtime(t_thinker *list);

void	*routine(void *list)
{
	t_thinker	*temp;

	temp = (t_thinker *)list;
	temp->time_start = ms_get_timeofday();
	if (temp->odd == true)
		usleep(10);
	printf("thread: %d foi inicializado!\n", temp->index);
	while (true)
	{
		fork_mutex_handler(list, get_fork);
	}
	return (NULL);
}

void	fork_mutex_handler(t_thinker *list, int status)
{
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;

	left_fork = list->prev->fork;
	right_fork = list->fork;
	if (status == get_fork)
	{
		pthread_mutex_lock(&left_fork);
		printf("%ld    %d   %s\n", (ms_get_timeofday() - list->time_start), \
		list->index, FORK);
		pthread_mutex_lock(&right_fork);
		printf("%ld    %d   %s\n", (ms_get_timeofday() - list->time_start), \
		list->index, FORK);
	}
	else
	{
		pthread_mutex_unlock(&left_fork);
		pthread_mutex_unlock(&right_fork);
	}
	return ;
}

// void	printer_philo(char *string)
// {
// 	if (string)
// 	{
// 		printf("%lld philo %d %s\n", (get_time() - philo->all->time));
// 	}
// 	return ;
// }
