#include "philosophers.h"

long	ms_timeofday(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	waiting(unsigned long time)
{
	unsigned long	curr;

	curr = ms_timeofday();
	while (ms_timeofday() - curr < time)
		usleep(40);
}
