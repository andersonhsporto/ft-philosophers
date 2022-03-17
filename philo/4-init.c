/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:00:31 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 00:08:19 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*init_args(char **argv)
{
	t_philo	data_struct;

	data_struct.temp = 0;
	data_struct.nbr_philo = ft_atoi(argv[1]);
	data_struct.time_die = ft_atoi(argv[2]);
	data_struct.time_eat = ft_atoi(argv[3]);
	data_struct.time_sleep = ft_atoi(argv[4]);
	data_struct.optional = ft_atoi(argv[6]);
	return (data_struct);
}
