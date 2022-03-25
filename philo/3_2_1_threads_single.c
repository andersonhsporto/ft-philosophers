/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_1_threads_single.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:39:09 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 21:43:14 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	one_philo_exec(t_thinker *list)
{
	pthread_mutex_lock(&list->is_dead);
	pthread_mutex_lock(&list->fork);
	printf("%ld    %d   %s\n", (ms_timeofday() - list->time_start), \
		list->index, FORK);
	waiting(list->data->args.time_die);
	printf("%ld    %d   %s\n", (ms_timeofday() - list->time_start), \
		list->index, DIE);
}