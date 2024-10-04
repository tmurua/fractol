/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:58:04 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/04 02:50:58 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* converts a string into a double // based on same principle as ft_atoi */
double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	int		i;

	i = 0;
	sign = handle_sign(str, &i);
	result = handle_integer_part(str, &i);
	if (str[i] == '.')
		result = result + handle_decimal_part(str, &i);
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

double	handle_integer_part(const char *str, int *i)
{
	double	result;

	result = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

double	handle_decimal_part(const char *str, int *i)
{
	double	decimal;
	double	divisor;

	decimal = 0.0;
	divisor = 1.0;
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		decimal = decimal * 10.0 + (str[*i] - '0');
		divisor = divisor * 10.0;
		(*i)++;
	}
	return (decimal / divisor);
}
