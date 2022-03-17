/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:55:49 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/16 23:21:16 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;
	int		index;

	number = 0;
	sign = 1;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index++] == '-')
			sign = -1;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		number = number * 10 + (str[index] - '0');
		index++;
		if (number > 2147483647 && sign == 1)
			return (-1);
		if (number > 2147483648 && sign == -1)
			return (0);
	}
	return (sign * (int)number);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
