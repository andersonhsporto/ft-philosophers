/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:01:00 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/21 03:09:41 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define OPTIONAL "number of times each philosopher must eat"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef enum e_actions
{
	tk_fork,
	eating,
	is_sleep,
	thinking,
	dead
};

enum	e_arg
{
	number_of_philosophers,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	number_of_times_each_philosopher_must_eat
};

typedef struct s_thinker
{
	int					index;
	pthread_t			thread;
	struct s_thinker	*next;
}	t_thinker;

typedef struct s_philo
{
	int	temp;
	int	nbr_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	optional;
}	t_philo;

int			inspect_args(int argc, char **argv);
int			ft_atoi(const char *str);
int			inspect_char(int c);

t_philo		init_args(char **argv);

t_thinker	*lstnew_think(int index);
t_thinker	*lstlast_think(t_thinker *lst);
void		lstadd_back_think(t_thinker **lst, t_thinker *new);
int			lstsize_think(t_thinker *lst);

#endif