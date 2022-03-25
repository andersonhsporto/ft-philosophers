/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_threads_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:32:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/25 11:06:45 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_thinker *list, char *message)
{
	long	time;

	time = ms_timeofday();
	pthread_mutex_lock(&list->data->print_lock);
	if (philo_is_dead(list->data) == false)
	{
		printf("%ld\t%d %s\n", (time - list->time_start), list->index, message);
	}
	pthread_mutex_unlock(&list->data->print_lock);
}
