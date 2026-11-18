/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahed-dar <ahed-dar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:31:34 by ahed-dar          #+#    #+#             */
/*   Updated: 2026/11/16 12:00:00 by ahed-dar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;
	int	ret;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count = 1;
		n = -n;
	}
	ret = putnbr_base((unsigned long)n, "0123456789");
	if (ret == -1)
		return (-1);
	return (count + ret);
}
