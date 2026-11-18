/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahed-dar <ahed-dar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:31:34 by ahed-dar          #+#    #+#             */
/*   Updated: 2026/11/16 12:00:00 by ahed-dar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_base(unsigned long nbr, const char *base)
{
	unsigned long	base_s;
	int				count;
	int				ret;

	base_s = ft_strlen(base);
	count = 0;
	if (nbr >= base_s)
	{
		ret = putnbr_base(nbr / base_s, base);
		if (ret == -1)
			return (-1);
		count = ret;
	}
	if (write(1, &base[nbr % base_s], 1) == -1)
		return (-1);
	return (count + 1);
}
