/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_threads_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:32:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/26 22:49:34 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_thinker *list, char *message)
{
	size_t	time;

	if (philo_is_dead(list->data) == false)
	{
		time = ms_timeofday();
		pthread_mutex_lock(&list->data->print_lock);
		printf("%ld\t%d %s\n", (time - list->time_start), list->index, message);
		pthread_mutex_unlock(&list->data->print_lock);
		return ;
	}
	return ;
}

void	print_death(t_thinker *list)
{
	size_t	time;

	if (philo_is_dead(list->data) == false)
	{
		time = ms_timeofday();
		list->data->is_dead = true;
		pthread_mutex_lock(&list->data->print_lock);
		printf("%zu\t%d %s\n", (time - list->time_start), list->index, DIE);
		pthread_mutex_destroy(&list->data->death_lock);
		pthread_mutex_destroy(&list->data->print_lock);
		return ;
	}
	return ;
}

