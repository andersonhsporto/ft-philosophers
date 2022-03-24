#include "philosophers.h"

void	create_mutex(t_philo *data);
int		create_threads(t_philo *data);
int		join_threads(t_philo *data);

void	start_threads(t_philo *data)
{
	data->list = start_list(data);
	create_mutex(data);
	if (!create_threads(data))
	{
		printf("Error de thread\n");
		//free no que tava alocado
	}
	if (!join_threads(data))
	{
		printf("Error join\n");
	}
	is_alive(data);
}

void	create_mutex(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
	while (index > 0)
	{
		pthread_mutex_init(&temp->fork, NULL);
		pthread_mutex_init(&temp->is_dead, NULL);
		index--;
		temp = temp->next;
	}
	return ;
}

int	create_threads(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
	while (index > 0)
	{
		if (pthread_create(&(temp->thread), NULL, &routine, (void *)temp))
		{
			return (0);
		}
		temp = temp->next;
		index--;
	}
	return (1);
}

int	join_threads(t_philo *data)
{
	t_thinker	*temp;
	int			index;

	temp = data->list;
	index = data->list->list_size;
	while (index > 0)
	{
		if (pthread_join(temp->thread, NULL))
		{
			return (0);
		}
		index--;
		temp = temp->next;
	}
	return (1);
}
