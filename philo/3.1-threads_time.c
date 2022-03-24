/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.1-threads_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/24 02:24:06 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ms_get_timeofday(void)
{
	struct timeval	ts;
	size_t			milliseconds;

	gettimeofday(&ts, NULL);
	milliseconds = (ts.tv_sec * 1000) + (ts.tv_sec / 1000);
	return (milliseconds);
}

size_t	diff_time(size_t start)
{
	size_t	what_time;
	size_t	diff;

	what_time = ms_get_timeofday();
	diff = what_time - start;
	return (diff);
}
