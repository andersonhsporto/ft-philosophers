/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-philosophers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:48:39 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 12:50:02 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	data_philo;

	if (inspect_args(argc, argv))
	{
		data_philo = init_args(argv);
		printf("%d\n", data_philo.optional);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
