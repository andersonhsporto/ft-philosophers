/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-philosophers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:48:39 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/22 19:36:56 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	data_philo;

	if (inspect_args(argc, argv))
	{
		data_philo = init_args(argv);
		data_philo.i = 0;
		pthread_mutex_init(&data_philo.mutex, NULL);
		teste(&data_philo);
		pthread_mutex_destroy(&data_philo.mutex);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
