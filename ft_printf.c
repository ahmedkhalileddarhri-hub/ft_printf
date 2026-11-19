/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahed-dar <ahed-dar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:31:34 by ahed-dar          #+#    #+#             */
/*   Updated: 2026/11/18 05:22:15 by ahed-dar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 
static int	ft_next(const char *format, int *i, va_list ap)
{
	if (format[*i] != '%')
		return (write(1, &format[*i], 1));
	if (!format[*i + 1])
		return (-1);
	(*i)++;
	return (ft_format(format[*i], ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;
	int		ret;
	int		i;

	if (!format)
		return (-1);
	va_start(ap, format);
	total = 0;
	i = 0;
	while (format[i])
	{
		ret = ft_next(format, &i, ap);
		if (ret == -1)
		{
			va_end(ap);
			return (-1);
		}
		total += ret;
		i++;
	}
	va_end(ap);
	return (total);
}
