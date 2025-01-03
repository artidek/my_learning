/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:43:39 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/31 09:58:23 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	ft_set_flags(t_flags flags, char *format)
{
	char	*temp;

	temp = format;
	ft_memset(&flags, 0, sizeof(t_flags));
	while (*temp == ' ' || *temp == '-' || *temp == '+' || *temp == '#'
		|| *temp == '0')
	{
		if (*temp == '-')
			flags.minus++;
		if (*temp == ' ')
			flags.blank++;
		if (*temp == '#')
			flags.hash++;
		if (*temp == '+')
			flags.plus++;
		if (*temp == '0')
			flags.zero++;
		temp++;
	}
	return (ft_set_width(flags, temp));
}
