/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2-threads_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:08:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 02:37:15 by anhigo-s         ###   ########.fr       */
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
	if (temp->odd == true)
		usleep(50);
	printf("thread: %d foi inicializado!\n", temp->index);
	while (true)
	{
		get_fork(list);
		lunchtime(list);
		drop_fork(list);
		break ;
	}
	temp->data->i++;
	return (NULL);
}

void	get_fork(t_thinker *list)
{
	pthread_mutex_lock(&list->prev->fork);
	pthread_mutex_lock(&list->fork);
	printf(">%d< pegou garfo as %zu\n", list->index, diff_time(list->time_start));
	return ;
}

void	drop_fork(t_thinker *list)
{
	pthread_mutex_unlock(&list->prev->fork);
	pthread_mutex_unlock(&list->fork);
	printf(">%d< soltou garfo as %zu<\n", list->index, diff_time(list->time_start));
	return ;
}


// void	bedtime(t_thinker *list)
// {
// 	pthread_mutex_lock(&list->data->mutex);
// 	list->status = sleeping;
// 	usleep(750000);
// 	printf("Sonequinha do thread: %d\n", list->index);
// }

void	lunchtime(t_thinker *list)
{
	list->status = eating;
	usleep(1050000);
	printf("Lanchinho do %d\n", list->index);
}
