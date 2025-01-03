/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:09:35 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/02 23:10:58 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_hex(t_flags flags, int size, char **result, char *args)
{
	size = size - (int)ft_strlen((char *)args);
	if (flags.hash && size >= 3)
		size -= 3;
	if (!flags.zero && !flags.minus)
	{
		while (size-- > 0)
			*(*result)++ = ' ';
	}
	if (flags.hash)
	{
		*(*result)++ = '0';
		*(*result)++ = 'x';
	}
	if (flags.zero)
	{
		while (size-- > 0)
			*(*result)++ = '0';
	}
	while (*args)
	{
		*(*result)++ = *args++;
	}
	while (size-- > 0 && flags.minus)
		*(*result)++ = ' ';
	**result = '\0';
}
