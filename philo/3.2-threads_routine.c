/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2-threads_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:08:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/23 14:35:13 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	bedtime(t_thinker *list);

void	*routine(void *list)
{
	t_thinker	*temp;

	temp = (t_thinker *)list;
	pthread_mutex_lock(&temp->data->mutex);
	printf("<< racional %d time %zu teste = %d\n", temp->index, temp->last_meal, temp->data->i);
	bedtime(list);
	lunchtime(list);
	temp->data->i++;
	pthread_mutex_unlock(&temp->data->mutex);
}

void	bedtime(t_thinker *list)
{
	list->status = sleeping;
	usleep(750000);
	printf("Sonequinha do %d\n", list->index);
}

void	lunchtime(t_thinker *list)
{
	list->status = eating;
	usleep(1050000);
	printf("Ummmmmmm hora do lanche do %d\n", list->index);
}