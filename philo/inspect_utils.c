#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	inspect_char(int c)
{
	printf("%c\n", c);
	if (ft_isdigit(c) || c == '-')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
