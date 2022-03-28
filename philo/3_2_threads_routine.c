/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_threads_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:08:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/28 03:24:16 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	fork_mutex_handler(t_thinker *list, int action);
static void	lunchtime(t_thinker *list);
static void	sleeptime(t_thinker *list);
static void	thinktime(t_thinker *list);

void	*routine(void *ptr)
{
	t_thinker	*list;

	list = (t_thinker *)ptr;
	while (philo_is_dead(list->data) == false)
	{
		if (list->odd == true || all_odd_picked_up_a_fork(list))
		{
			fork_mutex_handler(list, get_fork);
			lunchtime(list);
			fork_mutex_handler(list, drop_fork);
			if (optional_handler(list))
			{
				printf("1\n");
				break ;
			}
			sleeptime(list);
			thinktime(list);
		}
	}
	return (NULL);
}

void	fork_mutex_handler(t_thinker *list, int action)
{
	if (list->data->args.nbr_philo == 1 && philo_is_dead(list->data) == false)
	{
		pthread_mutex_lock(&list->fork);
		print_action(list, FORK);
		waiting(list->data->args.time_die);
		return ;
	}
	else if (action == get_fork && philo_is_dead(list->data) == false)
	{
		pthread_mutex_lock(&list->prev->fork);
		print_action(list, FORK);
		pthread_mutex_lock(&list->fork);
		print_action(list, FORK);
		list->fork_taken = 1;
		return ;
	}
	else
	{
		pthread_mutex_unlock(&list->prev->fork);
		pthread_mutex_unlock(&list->fork);
		return ;
	}
}

static void	lunchtime(t_thinker *list)
{
	if (philo_is_dead(list->data) == false && !optional_handler(list))
	{
		pthread_mutex_lock(&list->sync);
		print_action(list, EAT);
		list->last_meal = (ms_timeofday());
		list->nbr_snacks++;
		pthread_mutex_unlock(&list->sync);
		waiting(list->data->args.time_eat);
		return ;
	}
	return ;
}

static void	sleeptime(t_thinker *list)
{
	if (philo_is_dead(list->data) == false)
	{
		print_action(list, SLEEP);
		waiting(list->data->args.time_sleep);
	}
	return ;
}

static void	thinktime(t_thinker *list)
{
	if (philo_is_dead(list->data) == false)
	{
		print_action(list, THINK);
	}
	return ;
}
