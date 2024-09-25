/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:07:34 by tmurua            #+#    #+#             */
/*   Updated: 2023/11/27 19:49:19 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	upper;

	if (c >= 'a' && c <= 'z')
		upper = c - ('a' - 'A');
	else
		upper = c;
	return (upper);
}
