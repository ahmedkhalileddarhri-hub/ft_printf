/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahed-dar <ahed-dar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:31:34 by ahed-dar          #+#    #+#             */
/*   Updated: 2026/11/18 08:06:48 by ahed-dar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unknown(char c)
{
	if (ft_putchar('%') == -1)
		return (-1);
	if (ft_putchar(c) == -1)
		return (-1);
	return (2);
}

int	ft_format(char format, va_list list)
{
	if (format == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (format == 's')
		return (ft_putstr(va_arg(list, char *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (format == 'u')
		return (putnbr_base(va_arg(list, unsigned int), "0123456789"));
	if (format == 'x')
		return (putnbr_base(va_arg(list, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF"));
	if (format == 'p')
		return (ft_putptr(va_arg(list, void *)));
	if (format == '%')
		return (ft_putchar('%'));
	return (ft_unknown(format));
}
