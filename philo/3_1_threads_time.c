/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_threads_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 13:30:08 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ms_timeofday(void)
{
	struct timeval	ts;

	gettimeofday(&ts, NULL);
	return ((ts.tv_sec * 1000) + (ts.tv_usec / 1000));
}

void	waiting(size_t time)
{
	size_t	curr;

	curr = ms_timeofday();
	while (ms_timeofday() - curr < time)
		usleep(40);
}
