/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:33:10 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/31 09:58:23 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_width(char **temp, int counter)
{
	if (**temp == '0')
		return (counter);
	while (**temp >= 48 && **temp <= 57)
	{
		counter++;
		(*temp)++;
	}
	return (counter);
}