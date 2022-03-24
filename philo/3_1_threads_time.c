/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_threads_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 15:21:22 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ms_timeofday(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	//printf(">>>>%ld \n", (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	waiting(unsigned long time)
{
	unsigned long	curr;

	curr = ms_timeofday();
	while (ms_timeofday() - curr < time)
		usleep(40);
}
