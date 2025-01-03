/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:58:20 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/03 10:54:18 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prt_arg(t_flags flags, va_list args, char *format, t_list *cargs)
{
	if (*format == 's')
		ft_print_str(flags, va_arg(args, char *), cargs);
	if (*format == 'c')
		ft_print_char(flags, va_arg(args, int), cargs);
	if (*format == 'd' || *format == 'i')
		ft_print_decimal(flags, va_arg(args, int), cargs);
	if (*format == 'u')
		ft_print_uint(flags, va_arg(args, unsigned int), cargs);
	if (*format == 'x')
		ft_print_x(flags, va_arg(args, long long int), cargs);
	if (*format == 'X')
		ft_print_cx(flags, va_arg(args, long long int), cargs);
	if (*format == 'p')
		ft_print_pointer(flags, va_arg(args, void *), cargs);
}
