/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:01:00 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 00:08:53 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define OPTIONAL "number of times each philosopher must eat"

enum	e_arg
{
	number_of_philosophers,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	number_of_times_each_philosopher_must_eat
};

typedef struct s_philo
{
	int	temp;
	int	nbr_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	optional;
}	t_philo;

int		inspect_args(int argc, char **argv);
int		ft_atoi(const char *str);
int		inspect_char(int c);

t_philo	*init_args(char **argv);

#endif