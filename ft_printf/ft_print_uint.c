/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:40:36 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/06 10:07:34 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags, char *conv)
{
	if (flags.minus || flags.msize >= 0)
		flags.zero = 0;
	flags.width -= (int)ft_strlen(conv);
	if (flags.msize > (int)ft_strlen(conv))
		flags.width -= ((flags.msize - (int)ft_strlen(conv)));
	return (flags);
}

void	ft_print_uint(t_flags flags, unsigned int args, t_list *cargs)
{
	char	*conv;
	t_flags	o_flags;

	conv = ft_utoa((unsigned int)args);
	o_flags = override_flags(flags, conv);
	if (conv[0] == '0' && o_flags.msize == 0)
	{
		o_flags = override_flags(flags, "");
		ft_print_digit(o_flags, "", cargs);
	}
	else
		ft_print_digit(o_flags, conv, cargs);
	free(conv);
}
