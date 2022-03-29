/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_threads_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:08:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/29 03:45:57 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*main_routine(void *ptr)
{
	t_thinker	*list;

	list = (t_thinker *)ptr;
	list->time_start = timenow();
	list->last_meal = list->time_start;
	if (list->index % 2 == 0)
		new_usleep(list->data->args.time_eat);
	while (list->data->philo_alive == true)
	{
		if (list->data->args.nbr_philo == 1)
		{
			pthread_mutex_lock(&list->fork);
			pthread_mutex_lock(&list->data->printer_mutex);
			printf("%zu\t%s %d\n", \
				(timenow() - list->time_start), FORK, list->index);
			pthread_mutex_unlock(&list->data->printer_mutex);
			new_usleep(list->data->args.time_die);
		}
		fork_lock(list);
		lunchtime(list);
		fork_unlock(list);
		naptime(list);
		thinker(list);
	}
	return (NULL);
}
