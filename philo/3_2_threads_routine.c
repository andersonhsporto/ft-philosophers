/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_threads_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:08:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/29 02:23:28 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*main_routine(void *ptr)
{
	t_thinker	*list;

	list = (t_thinker *)ptr;
	list->time_start = timenow();
	if (list->index % 2)
		new_usleep(list->data->args.time_eat);
	while (list->data->philo_alive == true)
	{
		fork_lock(list);
		lunchtime(list);
		fork_unlock(list);
		naptime(list);
		thinker(list);
	}
	return (NULL);
}
