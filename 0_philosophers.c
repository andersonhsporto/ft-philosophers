/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_philosophers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:48:39 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/29 13:16:17 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	data_philo;

	if (inspect_args(argc, argv))
	{
		data_philo = init_args(argv);
		start_threads(&data_philo);
		free_think(&data_philo);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
