/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:53:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 15:59:50 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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