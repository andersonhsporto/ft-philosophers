/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_threads_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:08:44 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/28 03:09:19 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	thread_death(t_thinker *list);

void	*death_routine(void *ptr)
{
	t_thinker	*list;

	list = (t_thinker *)ptr;
	while (true)
	{
		pthread_mutex_lock(&list->sync);
		if (optional_handler(list))
		{
			list->data->is_dead = true;
			break ;
		}
		else if ((list->data->args.optional != 0) && \
			list->nbr_snacks >= list->data->args.optional)
			break ;
		else if (thread_death(list))
			break ;
		pthread_mutex_unlock(&list->sync);
		list = list->next;
	}
	pthread_mutex_destroy(&list->sync);
	return (NULL);
}

static int	thread_death(t_thinker *list)
{
	t_thinker	*temp;

	temp = list;
	if (temp->nbr_snacks == 0 && \
		((ms_timeofday() - temp->time_start) >= (temp->data->args.time_die)))
	{
		print_death(temp);
		return (true);
	}
	else if (temp->nbr_snacks > 0 && \
		((ms_timeofday() - temp->last_meal) >= (temp->data->args.time_die)))
	{
		print_death(temp);
		return (true);
	}
	else
	{
		return (false);
	}
}

int	philo_is_dead(t_philo *data)
{
	if (data->is_dead == true)
	{
		pthread_mutex_destroy(&data->death_mutex);
		return (true);
	}
	else
	{
		return (false);
	}
}
