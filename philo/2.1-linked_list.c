/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.1-linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 02:45:43 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/21 03:22:18 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_thinker	*lstnew_think(int index)
{
	t_thinker	*element;

	element = malloc(sizeof(t_thinker));
	if (element)
	{
		element->index = index;
		element->next = (0);
		return (element);
	}
	return (0);
}

t_thinker	*lstlast_think(t_thinker *lst)
{
	if (lst)
	{
		while (lst->next != 0)
		{
			lst = lst->next;
		}
		return (lst);
	}
	return (0);
}

void	lstadd_back_think(t_thinker **lst, t_thinker *new)
{
	t_thinker	*temp;

	if (*lst)
	{
		temp = lstlast_think(*lst);
		temp->next = new;
	}
	else
	{
		*lst = new;
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

t_thinker	*start_list(int size)
{
	t_thinker	*list;
	int			index;

	list = lstnew_think(0);
	index = 1;
	while (index < size)
	{
		lstadd_back_think(list, lstnew_think(index));
		index++;
	}
	return (list);
}
