/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.1-linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 02:45:43 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/23 16:26:48 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_odd(int index);

t_thinker	*lstnew_think(int index, t_philo *data, int size)
{
	t_thinker	*element;

	element = malloc(sizeof(t_thinker));
	if (element)
	{
		element->index = index;
		element->status = is_odd(index);
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
		return (1);
	}
	else
	{
		return (0);
	}
}

void	lstadd_back_think(t_thinker *lst, t_thinker *new)
{
	if (lst)
	{
		new->next = lst->next;
		new->prev = lst;
		(lst)->next->prev = new;
		(lst)->next = new;
		(lst) = new;
	}
	else
	{
		lst = new;
	}
}

int	lstsize_think(t_thinker *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_thinker	*start_list(t_philo *data)
{
	t_thinker	*list;
	int			index;

	list = lstnew_think(data->args.nbr_philo, data, data->args.nbr_philo);
	index = 1;
	while (index < data->args.nbr_philo)
	{
		lstadd_back_think(list, lstnew_think(index, data, data->args.nbr_philo));
		index++;
	}
	// print_list(list);
	return (list);
}

//remover
void print_list(t_thinker *list)
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