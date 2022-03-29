/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5_threads_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:08:44 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/28 22:32:48 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutex(t_thinker *list)
{
	t_thinker	*temp;
	int			index;

	temp = list;
	index = list->list_size;
	while (index > 0)
	{
		pthread_mutex_destroy(&list->eat_mutex);
		pthread_mutex_destroy(&list->fork);
		index--;
	}
	pthread_mutex_destroy(&list->data->printer_mutex);
}

void	*death_routine(void *ptr)
{
	t_thinker	*list;

	list = (t_thinker *)ptr;
	while (list->data->philo_alive == true)
	{
		pthread_mutex_lock(&list->eat_mutex);
		pthread_mutex_lock(&list->data->printer_mutex);
		if ((timenow() - list->last_meal) >= list->data->args.time_die)
		{
			list->data->philo_alive = false;
			printf("%zu\t%s %d\n", \
				(timenow() - list->time_start), DIE, list->index);
			break ;
		}
		pthread_mutex_unlock(&list->eat_mutex);
		pthread_mutex_unlock(&list->data->printer_mutex);
	}
	destroy_mutex(list);
	return (NULL);
}
