/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:01:00 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/30 14:07:54 by anhigo-s         ###   ########.fr       */
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

enum e_bool
{
	false,
	true
};

enum e_actions
{
	get_fork,
	drop_fork
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
	int			nbr_philo;
	size_t		time_die;
	int			time_eat;
	int			time_sleep;
	int			optional;
}	t_args;

typedef struct s_thinker
{
	int					index;
	int					nbr_snacks;
	size_t				last_meal;
	size_t				time_start;
	pthread_t			thread;
	pthread_mutex_t		fork;
	pthread_mutex_t		eat_mutex;
	struct s_philo		*data;
	struct s_thinker	*prev;
	struct s_thinker	*next;
	int					list_size;
}	t_thinker;

typedef struct s_philo
{
	pthread_t			death;
	pthread_mutex_t		printer_mutex;
	int					philo_alive;
	t_args				args;
	t_thinker			*list;
}	t_philo;

int			inspect_args(int argc, char **argv);
int			inspect_char(int c);
int			ft_atoi(const char *str);

t_philo		init_args(char **argv);

t_thinker	*start_list(t_philo *data);

void		start_threads(t_philo *data);

void		*main_routine(void *ptr);
void		*death_routine(void *ptr);

void		print_action(t_thinker *list, char *message);
void		print_death(t_thinker *list);

int			philo_is_dead(t_philo *data);

size_t		timenow(void);
void		waiting(size_t time_in_ms);

int			all_odd_picked_up_a_fork(t_thinker *list);
int			optional_handler(t_thinker *list);

void		free_think(t_philo *data);

void		fork_lock(t_thinker *list);
void		lunchtime(t_thinker *list);
void		fork_unlock(t_thinker *list);
void		naptime(t_thinker *list);
void		thinker(t_thinker *list);
#endif