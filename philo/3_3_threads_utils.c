/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_threads_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:32:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/28 03:10:55 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_thinker *list, char *message)
{
	size_t	time;

	pthread_mutex_lock(&list->data->death_mutex);
	if (philo_is_dead(list->data) == false)
	{
		time = ms_timeofday();
		printf("%ld\t%d %s\n", (time - list->time_start), list->index, message);
		pthread_mutex_unlock(&list->data->death_mutex);
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
		printf("%zu\t%d %s\n", (time - list->time_start), list->index, DIE);
		return ;
	}
	return ;
}

int	all_odd_picked_up_a_fork(t_thinker *list)
{
	t_thinker	*temp;
	int			index;
	int			odd_counter;

	temp = list;
	index = 0;
	odd_counter = 0;
	while (index < list->list_size)
	{
		if (is_odd(temp->index) && temp->fork_taken == 1)
		{
			odd_counter++;
		}
		index++;
		temp = temp->prev;
	}
	index = list->list_size;
	if (list->list_size % 2 != 0)
		index++;
	if (odd_counter == (index / 2))
		return (1);
	else
		return (0);
}

int	optional_handler(t_thinker *list)
{
	t_thinker	*temp;
	int			index;
	int			counter;

	temp = list;
	counter = 0;
	index = 0;
	while (index < list->list_size)
	{
		if (temp->nbr_snacks >= temp->data->args.optional)
		{
			counter++;
		}
		index++;
		temp = temp->next;
	}
	if (counter == list->list_size && list->data->args.optional != 0)
	{
		list->data->is_dead = true;
		return (1);
	}
	else
		return (0);
}
