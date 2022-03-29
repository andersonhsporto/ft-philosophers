/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_threads_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:08:44 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/29 03:35:48 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	optinal_handler(t_thinker *list);
static void	unlock_all_mutex(t_thinker *list);

void	*death_routine(void *ptr)
{
	t_thinker	*list;

	list = (t_thinker *)ptr;
	new_usleep(list->data->args.time_eat / 2);
	while (list->data->philo_alive == true)
	{
		pthread_mutex_lock(&list->eat_mutex);
		pthread_mutex_lock(&list->data->printer_mutex);
		if (optinal_handler(list))
			break ;
		if ((timenow() - list->last_meal) >= list->data->args.time_die)
		{
			list->data->philo_alive = false;
			printf("%zu\t%s %d\n", \
				(timenow() - list->time_start), DIE, list->index);
			break ;
		}
		pthread_mutex_unlock(&list->eat_mutex);
		pthread_mutex_unlock(&list->data->printer_mutex);
	}
	unlock_all_mutex(list);
	return (NULL);
}

static int	optinal_handler(t_thinker *list)
{
	t_thinker	*temp;
	int			index;
	int			nbr;

	temp = list;
	index = temp->list_size;
	nbr = 1;
	while (index > 0)
	{
		if (temp->data->args.optional == 0 || \
			(temp->nbr_snacks < temp->data->args.optional))
		{
			nbr = 0;
		}
		temp = temp->next;
		index--;
	}
	return (nbr);
}

static void	unlock_all_mutex(t_thinker *list)
{
	t_thinker	*temp;
	int			index;

	temp = list;
	index = list->list_size;
	temp->data->philo_alive = false;
	pthread_mutex_unlock(&temp->data->printer_mutex);
	pthread_mutex_destroy(&temp->data->printer_mutex);
	while (index > 0)
	{
		pthread_mutex_unlock(&temp->eat_mutex);
		pthread_mutex_destroy(&temp->eat_mutex);
		pthread_mutex_unlock(&temp->fork);
		pthread_mutex_destroy(&temp->fork);
		pthread_mutex_unlock(&temp->death_mutex);
		pthread_mutex_destroy(&temp->death_mutex);
		index--;
		temp = temp->next;
	}
	return ;
}
