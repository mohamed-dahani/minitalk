/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:31:12 by mdahani           #+#    #+#             */
/*   Updated: 2024/12/01 17:18:05 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_alpha(va_list list, char c);

int	ft_printf(const char *string, ...)
{
	va_list	list;
	int		result;
	int		i;

	if (!string)
		return (-1);
	va_start(list, string);
	result = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			result += check_alpha(list, string[i]);
		}
		else
			result += ft_putchar(string[i]);
		i++;
	}
	va_end(list);
	return (result);
}

static int	check_alpha(va_list list, char c)
{
	int	result;

	result = 0;
	if (c == 'c')
		result += ft_putchar(va_arg(list, int));
	else if (c == 's')
		result += ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		result += ft_putnbr(va_arg(list, int));
	else if (c == 'p')
		result += convert_hexa(va_arg(list, unsigned long), 'l', 1);
	else if (c == 'u')
		result += convert_decimal(va_arg(list, unsigned int));
	else if (c == 'x')
		result += convert_hexa(va_arg(list, unsigned long), 'l', 0);
	else if (c == 'X')
		result += convert_hexa(va_arg(list, unsigned long), 'u', 0);
	else if (c == '%')
		result += ft_putchar(c);
	return (result);
}
