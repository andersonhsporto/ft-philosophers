/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_1_linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 02:45:43 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/08/04 12:31:29 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_thinker	*lstnew_think(int index, t_philo *data, int size);
static void			lstadd_back_think(t_thinker *lst, t_thinker *new);

t_thinker	*start_list(t_philo *data)
{
	t_thinker	*list;
	int			index;

	list = lstnew_think(data->args.nbr_philo, data, data->args.nbr_philo);
	if (data->args.nbr_philo == 1)
		return (list);
	index = 1;
	while (index < data->args.nbr_philo)
	{
		lstadd_back_think(list, lstnew_think(index, data, \
		data->args.nbr_philo));
		index++;
	}
	return (list);
}

static t_thinker	*lstnew_think(int index, t_philo *data, int size)
{
	t_thinker	*element;

	element = malloc(sizeof(t_thinker));
	if (element)
	{
		element->index = index;
		element->nbr_snacks = 0;
		element->data = data;
		element->next = element;
		element->prev = element;
		element->list_size = size;
		return (element);
	}
	return (NULL);
}

static void	lstadd_back_think(t_thinker *lst, t_thinker *new)
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
