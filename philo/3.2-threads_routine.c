/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2-threads_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:08:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/23 22:35:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	bedtime(t_thinker *list);
void	lunchtime(t_thinker *list);

void	*routine(void *list)
{
	t_thinker	*temp;

	temp = (t_thinker *)list;

	temp->time_start = ms_get_timeofday();
	printf("<< racional %d prev-index %d time-prev %d\n", temp->index, temp->prev->index, temp->time_start);
	while (true)
	{
		bedtime(list);
		lunchtime(list);
		break ;
	}
	temp->data->i++;
}

void	bedtime(t_thinker *list)
{
	pthread_mutex_lock(&list->data->mutex);
	list->status = sleeping;
	usleep(750000);
	printf("Sonequinha do thread: %d\n", list->index);
}

void	lunchtime(t_thinker *list)
{
	list->status = eating;
	usleep(1050000);
	printf("Lanchinho do %d\n", list->index);
	pthread_mutex_unlock(&list->data->mutex);
}
