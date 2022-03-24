#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	data_philo;

	if (inspect_args(argc, argv))
	{
		data_philo = init_args(argv);
		start_threads(&data_philo);
		free_think(&data_philo);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
