/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_threads_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:08:44 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/25 10:54:16 by anhigo-s         ###   ########.fr       */
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

void	is_alive(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = 0;
	while (index < data->args.nbr_philo)
	{
		if (temp->status == endgame)
			break ;
		if ((ms_timeofday() - temp->last_meal) >= data->args.time_die)
		{
			printf("%ld    %d   %s\n", (ms_timeofday() - temp->time_start), \
				temp->index, DIE);
			temp->status = dead;
			temp->loop = 0;
			index++;
			pthread_mutex_destroy(&temp->is_dead);
		}
		temp = temp->next;
	}
}
