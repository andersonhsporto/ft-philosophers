/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.0-threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:22:34 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/21 03:23:12 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void* routine(void)
{
    printf("AQUI racional \n");
}

void	teste(t_philo *data)
{
	printf("TESTE %d\n", data->nbr_philo);
	int	i = data->nbr_philo;
	t_thinker	*list = start_list(data->nbr_philo);
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_create(&list->thread, NULL, &routine, NULL);
		i++;
	}
	return ;
}