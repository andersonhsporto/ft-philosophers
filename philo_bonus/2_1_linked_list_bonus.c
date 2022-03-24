#include "philosophers.h"

int	is_odd(int index);

t_thinker	*lstnew_think(int index, t_philo *data, int size)
{
	t_thinker	*element;

	element = malloc(sizeof(t_thinker));
	if (element)
	{
		element->index = index;
		element->odd = is_odd(index);
		element->status = 0;
		element->time_start = 0;
		element->nbr_snacks = 0;
		element->loop = 1;
		element->data = data;
		element->next = element;
		element->prev = element;
		element->list_size = size;
		return (element);
	}
	return (NULL);
}

int	is_odd(int index)
{
	if (index % 2 == 0)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

void	lstadd_back_think(t_thinker *lst, t_thinker *new)
{
	if (lst)
	{
		new->next = lst->next;
		new->prev = lst;
		lst->next->prev = new;
		lst->next = new;
		lst = new;
	}
	else
	{
		lst = new;
	}
}

t_thinker	*start_list(t_philo *data)
{
	t_thinker	*list;
	int			index;

	list = lstnew_think(data->args.nbr_philo, data, data->args.nbr_philo);
	index = 1;
	while (index < data->args.nbr_philo)
	{
		lstadd_back_think(list, \
			lstnew_think(index, data, data->args.nbr_philo));
		index++;
	}
	// print_list(list);
	return (list);
}

//remover
void	print_list(t_thinker *list)
{
	t_thinker	*temp;
	int			index;

	printf(">>>size: %d\n", list->list_size);
	temp = list;
	index = list->list_size;
	while (index > 0)
	{
		index--;
		printf(">>>list: %d node index\n", temp->index);
		temp = temp->next;
	}
	return ;
}
