/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:05:23 by mdahani           #+#    #+#             */
/*   Updated: 2024/11/30 18:11:46 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_decimal(unsigned int nbr)
{
	int	result;

	result = 0;
	if (nbr >= 10)
	{
		result += convert_decimal(nbr / 10);
		result += convert_decimal(nbr % 10);
	}
	else
		result += ft_putchar(nbr + '0');
	return (result);
}
