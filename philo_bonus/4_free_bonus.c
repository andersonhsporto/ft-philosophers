#include "philosophers.h"

void	free_think(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	index = data->args.nbr_philo;
	while (index > 0)
	{
		temp = data->list;
		data->list = data->list->next;
		free(temp);
		index--;
	}
	return ;
}