/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5_threads_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:08:44 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/28 19:29:43 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*death_routine(void *ptr)
{
	t_thinker	*list;

	list = (t_thinker *)ptr;
	while (true)
	{
		pthread_mutex_lock(&list->eat_mutex);
		pthread_mutex_lock(&list->data->printer_mutex);
		if ((timenow() - list->last_meal) >= list->data->args.time_die)
		{
			printf("%zu\t%s %d\n", \
				(timenow() - list->time_start), DIE, list->index);
			return (NULL);
		}
		pthread_mutex_unlock(&list->eat_mutex);
		pthread_mutex_unlock(&list->data->printer_mutex);
	}
	return (NULL);
}
