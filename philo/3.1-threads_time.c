/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.1-threads_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/21 16:56:24 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ms_get_timeofday(void)
{
	struct timeval	ts;
	size_t			milliseconds;

	gettimeofday(&ts, NULL);
	milliseconds = ((size_t)ts.tv_sec * 1000) + (ts.tv_sec / 1000);
	return (milliseconds);
}
