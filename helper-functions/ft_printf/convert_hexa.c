/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:57:46 by mdahani           #+#    #+#             */
/*   Updated: 2024/12/02 19:00:39 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	generate_address(unsigned long nbr, char type);

int	convert_hexa(unsigned long nbr, char type, int is_true)
{
	int	result;

	if (!is_true)
		nbr = (unsigned int) nbr;
	if (!nbr)
	{
		if (!is_true)
			return (write(1, "0", 1));
		return (write(1, "(nil)", 5));
	}
	result = 0;
	if (is_true)
		result += ft_putstr("0x");
	result += generate_address(nbr, type);
	return (result);
}

static int	generate_address(unsigned long nbr, char type)
{
	int		result;
	char	*hexa_digits;

	result = 0;
	if (type == 'l')
		hexa_digits = "0123456789abcdef";
	else
		hexa_digits = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		result += generate_address(nbr / 16, type);
		result += generate_address(nbr % 16, type);
	}
	else
		result += ft_putchar(hexa_digits[nbr]);
	return (result);
}
