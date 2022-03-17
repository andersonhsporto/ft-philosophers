/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:03:27 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/16 23:41:40 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_arg_error(int index);

int	inspect_args(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc == 5 || argc == 6)
	{
		while (index < argc)
		{
			if (atoi_fchar(argv[index]) < 1)
			{
				print_arg_error(index);
				return (0);
			}
			index++;
		}
		return (1);
	}
	printf("philo: argument error\n");
	return (0);
}

int	atoi_fchar(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (inspect_char(string[index]))
			return (-1);
		index++;
	}
	return (ft_atoi(string));
}

void	print_arg_error(int index)
{
	if (index == number_of_philosophers)
		printf("philo: error in 'number of philosophers' argument\n");
	else if (index == time_to_die)
		printf("philo: error in 'time to die' argument\n");
	else if (index == time_to_eat)
		printf("philo: error in 'time to eat' argument\n");
	else if (index == time_to_sleep)
		printf("philo: error in 'time to sleep' argument\n");
	else if (index == number_of_times_each_philosopher_must_eat)
		printf("philo: error in optional argument: (%s)\n", OPTIONAL);
}
