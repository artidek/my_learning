/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:46:12 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/31 09:58:23 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	ft_set_width(t_flags flags, char *format)
{
	if (*format > 48 && *format <= 57)
		flags.width = ft_atoi(format);
	return (flags);
}
