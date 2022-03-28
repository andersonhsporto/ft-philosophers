/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_threads_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/28 16:52:53 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	timenow(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	waiting(size_t time)
{
	size_t	time_now;

	time_now = timenow();
	while ((timenow() - time_now) < (size_t)time)
	{
		usleep(20);
	}
}

void	new_usleep(size_t time_in_ms)
{
	size_t	start_time;

	start_time = timenow();
	usleep((time_in_ms - 10) * 1000);
	while ((timenow() - time_in_ms) < start_time)
		;
}
