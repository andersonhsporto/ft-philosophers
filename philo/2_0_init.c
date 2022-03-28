/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_0_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:00:31 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/28 01:19:51 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	init_args(char **argv)
{
	t_philo	data_struct;

	data_struct.args.nbr_philo = ft_atoi(argv[1]);
	data_struct.args.time_die = ft_atoi(argv[2]);
	data_struct.args.time_eat = ft_atoi(argv[3]);
	data_struct.args.time_sleep = ft_atoi(argv[4]);
	data_struct.is_dead = false;
	if (argv[5])
	{
		data_struct.args.optional = ft_atoi(argv[5]);
		return (data_struct);
	}
	else
	{
		data_struct.args.optional = 0;
		return (data_struct);
	}
}
