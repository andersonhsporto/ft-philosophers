/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.0-threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:22:34 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 02:42:04 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *list);
int		create_threads(t_philo *data);
int		join_threads(t_philo *data);

void	teste(t_philo *data)
{
	data->list = start_list(data);
	if (!create_threads(data))
	{
		printf("Error de thread\n");
		//free no que tava alocado
	}
	if (!join_threads(data))
	{
		printf("Error join\n");
	}
}

int	create_threads(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
	while (index > 0)
	{
		if (pthread_create(&(temp->thread), NULL, &routine, (void *)temp))
		{
			return (0);
		}
		// if (pthread_detach(temp->thread))
		// {
		// 	return (0);
		// }
		// temp->last_meal = ms_get_timeofday();
		temp = temp->next;
		index--;
	}
	return (1);
}

int	join_threads(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
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
