/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_threads_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:08:44 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 21:45:29 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
