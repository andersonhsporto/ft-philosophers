/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_threads_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:08:44 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/27 23:47:57 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_is_dead(t_philo *data)
{
	pthread_mutex_lock(&data->death_lock);
	if (data->is_dead == true)
	{
		pthread_mutex_unlock(&data->death_lock);
		return (true);
	}
	else
		pthread_mutex_unlock(&data->death_lock);
	return (false);
}

int	thread_death(t_thinker *list)
{
	t_thinker	*temp;

	temp = list;

	if (all_odd_picked_up_a_fork(temp) && temp->nbr_snacks == 0 && (ms_timeofday() - temp->time_start) >= temp->data->args.time_die)
	{
		printf("SNACK 0\n");
		print_death(temp);
		return (true);
	}
	if (temp->nbr_snacks > 0 && ((ms_timeofday() - temp->last_meal) >= (temp->data->args.time_die)))
	{
		printf("%d index, %ld > %ld\n", temp->index, ((ms_timeofday() - temp->last_meal)), (temp->data->args.time_die));
		print_death(temp);
		return (true);
	}
	else
	{
		return (false);
	}
}

void	*death_routine(void *ptr)
{
	t_thinker	*list;

	printf("Death Start thread\n");
	list = (t_thinker *)ptr;
	while (true)
	{
		if ((list->data->args.optional != 0) && list->nbr_snacks >= list->data->args.optional)
			break ;
		if (thread_death(list))
			break ;
		list = list->next;
	}
	return (NULL);
}

