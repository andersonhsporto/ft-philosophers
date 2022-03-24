#include "philosophers.h"

void	is_alive(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = 0;
	while (index < data->args.nbr_philo)
	{
		if (temp->status == endgame)
			break ;
		if ((ms_timeofday() - temp->last_meal) >= data->args.time_die)
		{
			printf("%ld    %d   %s\n", (ms_timeofday() - temp->time_start), \
				temp->index, DIE);
			temp->status = dead;
			temp->loop = 0;
			index++;
			pthread_mutex_destroy(&temp->is_dead);
		}
		temp = temp->next;
	}
}
