/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:01:00 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/23 22:38:32 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define OPTIONAL	"number of times each philosopher must eat"
# define FORK		"has taken a fork"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DIE		"died"

typedef enum e_bool
{
	false,
	true
};

typedef enum e_actions
{
	tk_fork,
	eating,
	sleeping,
	thinking,
	dead,
	odd,
	even,
};

enum	e_arg
{
	number_of_philosophers,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	number_of_times_each_philosopher_must_eat
};

typedef struct s_args
{
	int			temp;
	int			nbr_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			optional;
}	t_args;

typedef struct s_thinker
{
	int					index;
	int					status;
	size_t				time_start;
	pthread_t			thread;
	pthread_mutex_t		forks;
	pthread_mutex_t		is_dead;
	size_t				last_meal;
	struct s_philo		*data;
	struct s_thinker	*prev;
	struct s_thinker	*next;
	int					list_size;
}	t_thinker;

typedef struct s_philo
{
	pthread_mutex_t	mutex;
	int 			i;
	t_args			args;
	t_thinker		*list;
}	t_philo;

int			inspect_args(int argc, char **argv);
int			ft_atoi(const char *str);
int			inspect_char(int c);

t_philo		init_args(char **argv);

t_thinker	*lstnew_think(int index, t_philo *data, int size);
t_thinker	*lstlast_think(t_thinker *lst);
void		lstadd_back_think(t_thinker *lst, t_thinker *new);
int			lstsize_think(t_thinker *lst);
t_thinker	*start_list(t_philo *data);

size_t		ms_get_timeofday(void);

void	teste(t_philo *data);
#endif