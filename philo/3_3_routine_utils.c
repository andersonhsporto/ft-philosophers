/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_routine_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:56:58 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/29 03:58:28 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fork_lock(t_thinker *list)
{
	if (list->data->philo_alive == true)
	{
		pthread_mutex_lock(&list->fork);
		pthread_mutex_lock(&list->data->printer_mutex);
		if (list->data->philo_alive == true)
			printf("%zu\t%s %d\n", \
				(timenow() - list->time_start), FORK, list->index);
		pthread_mutex_unlock(&list->data->printer_mutex);
		pthread_mutex_lock(&list->prev->fork);
		pthread_mutex_lock(&list->data->printer_mutex);
		if (list->data->philo_alive == true)
			printf("%zu\t%s %d\n", \
				(timenow() - list->time_start), FORK, list->index);
		pthread_mutex_unlock(&list->data->printer_mutex);
		return ;
	}
	return ;
}

void	lunchtime(t_thinker *list)
{
	if (list->data->philo_alive == true)
	{
		pthread_mutex_lock(&list->eat_mutex);
		list->last_meal = timenow();
		list->nbr_snacks++;
		pthread_mutex_unlock(&list->eat_mutex);
		pthread_mutex_lock(&list->data->printer_mutex);
		if (list->data->philo_alive == true)
			printf("%zu\t%s %d\n", \
				(timenow() - list->time_start), EAT, list->index);
		pthread_mutex_unlock(&list->data->printer_mutex);
		new_usleep(list->data->args.time_eat);
		return ;
	}
	return ;
}

void	fork_unlock(t_thinker *list)
{
	pthread_mutex_unlock(&list->fork);
	pthread_mutex_unlock(&list->prev->fork);
	return ;
}

void	naptime(t_thinker *list)
{
	if (list->data->philo_alive == true)
	{
		pthread_mutex_lock(&list->data->printer_mutex);
		if (list->data->philo_alive == true)
			printf("%zu\t%s %d\n", \
				(timenow() - list->time_start), SLEEP, list->index);
		pthread_mutex_unlock(&list->data->printer_mutex);
		new_usleep(list->data->args.time_sleep);
		return ;
	}
	return ;
}

void	thinker(t_thinker *list)
{
	if (list->data->philo_alive == true)
	{
		pthread_mutex_lock(&list->data->printer_mutex);
		printf("%zu\t%s %d\n", \
			(timenow() - list->time_start), THINK, list->index);
		pthread_mutex_unlock(&list->data->printer_mutex);
	}
	return ;
}
