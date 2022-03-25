/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_threads_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:08:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/25 20:34:07 by anhigo-s         ###   ########.fr       */
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
	list->time_start = ms_timeofday();
	if (list->odd == true)
		usleep(50);
	//printf("Start thread --> %d\n", list->index);
	while (philo_is_dead(list->data) == false)
	{
		fork_mutex_handler(list, get_fork);
		lunchtime(list);
		fork_mutex_handler(list, drop_fork);
		sleeptime(list);
		thinktime(list);
	}
	list->status = endgame;
	return (NULL);
}

void	fork_mutex_handler(t_thinker *list, int action)
{
	if (action == get_fork && philo_is_dead(list->data) == false)
	{
		print_action(list, FORK);
		// if (philo_is_dead(list->data) == false)
		// 	pthread_mutex_unlock(&list->fork);
		pthread_mutex_lock(&list->prev->fork);
		print_action(list, FORK);
		// if (philo_is_dead(list->data) == false)
		// 	pthread_mutex_unlock(&list->prev->fork);
		return ;
	}
	else
	{
		pthread_mutex_unlock(&list->fork);
		pthread_mutex_unlock(&list->prev->fork);
	}
}

static void	lunchtime(t_thinker *list)
{
	if (philo_is_dead(list->data) == false)
	{
		list->last_meal = ms_timeofday();
		waiting(list->data->args.time_eat);
		if (philo_is_dead(list->data) == false)
			print_action(list, EAT);
		list->nbr_snacks++;
	}
	return ;
}

static void	sleeptime(t_thinker *list)
{
	if (philo_is_dead(list->data) == false)
	{
		list->last_meal = ms_timeofday();
		waiting(list->data->args.time_sleep);
		if (philo_is_dead(list->data) == false)
			print_action(list, SLEEP);
	}
	return ;
}

static void	thinktime(t_thinker *list)
{
	if (philo_is_dead(list->data) == false)
	{
		list->last_meal = ms_timeofday();
		print_action(list, THINK);
	}
	return ;
}
