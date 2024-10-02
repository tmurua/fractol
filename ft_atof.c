/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:58:04 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/02 19:59:41 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* converts a string into a double // based on same principle as ft_atoi */
double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	double	decimal;
	double	divisor;
	int		i;

	i = 0;
	sign = 1;
	result = 0.0;
	decimal = 0.0;
	divisor = 1.0;
	sign = handle_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			decimal = decimal * 10.0 + (str[i] - '0');
			divisor *= 10.0;
			i++;
		}
		result += decimal / divisor;
	}
	return (sign * result);
}

/* Sets sign to -1 for '-', 1 otherwise.*/
int	handle_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

