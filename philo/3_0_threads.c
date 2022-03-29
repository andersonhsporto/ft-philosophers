/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:22:34 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/29 03:31:14 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void		create_mutex(t_philo *data);
static int		create_threads(t_philo *data);
static void		join_threads(t_philo *data);

void	start_threads(t_philo *data)
{
	data->list = start_list(data);
	create_mutex(data);
	if (!create_threads(data))
	{
		printf("philosophers: thread error\n");
	}
	join_threads(data);
	return ;
}

static void	create_mutex(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
	pthread_mutex_init(&data->printer_mutex, NULL);
	while (index > 0)
	{
		pthread_mutex_init(&temp->eat_mutex, NULL);
		pthread_mutex_init(&temp->fork, NULL);
		pthread_mutex_init(&temp->death_mutex, NULL);
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
		temp->last_meal = 0;
		if (pthread_create(&(temp->thread), NULL, &main_routine, (void *)temp))
		{
			return (0);
		}
		index--;
		temp = temp->prev;
	}
	pthread_create(&(data->death), NULL, &death_routine, (void *)data->list);
	return (1);
}

static void	join_threads(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
	pthread_join(temp->data->death, NULL);
	while (index > 0)
	{
		pthread_join(temp->thread, NULL);
		index--;
		temp = temp->next;
	}
}
