/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahed-dar <ahed-dar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:31:34 by ahed-dar          #+#    #+#             */
/*   Updated: 2026/11/16 12:00:00 by ahed-dar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	int	ret;

	if (!p)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	ret = putnbr_base((unsigned long)p, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (ret + 2);
}
