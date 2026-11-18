/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahed-dar <ahed-dar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:31:34 by ahed-dar          #+#    #+#             */
/*   Updated: 2026/11/16 12:05:13 by ahed-dar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
int		ft_putchar(int c);
int		ft_putstr(const char *s);
int		ft_putnbr(int n);
int		ft_putptr(void *p);
int		putnbr_base(unsigned long nbr, const char *base);
int		ft_format(char format, va_list list);
int		ft_printf(const char *format, ...);

#endif
