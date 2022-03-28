/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:22:34 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/28 03:25:02 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void		create_mutex(t_philo *data);
static int		create_threads(t_philo *data);
static int		join_threads(t_philo *data);

void	start_threads(t_philo *data)
{
	data->list = start_list(data);
	create_mutex(data);
	if (!create_threads(data))
	{
		printf("philosophers: thread error\n");
	}
	if (!join_threads(data))
	{
		printf("philosophers: join error\n");
	}
	return ;
}

static void	create_mutex(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
	while (index > 0)
	{
		pthread_mutex_init(&temp->fork, NULL);
		pthread_mutex_init(&temp->sync, NULL);
		index--;
		temp = temp->next;
	}
	return ;
}

static int	create_threads(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
	while (index > 0)
	{
		temp->time_start = ms_timeofday();
		if (pthread_create(&(temp->thread), NULL, &routine, (void *)temp))
		{
			return (0);
		}
		index--;
		temp = temp->prev;
	}
	pthread_create(&(temp->data->death), NULL, &death_routine, (void *)temp);
	return (1);
}

static int	join_threads(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
	pthread_join(temp->data->death, NULL);
	while (index > 0)
	{
		if (pthread_join(temp->thread, NULL))
		{
			return (0);
		}
		index--;
		temp = temp->next;
	}
	return (1);
}
