/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:28:30 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/30 16:52:29 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

static int	base_val(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int	atob(char *num)
{
	int		res;
	int		hexval;
	int		i;

	res = 0;
	i = 0;
	while (num[i])
	{
		hexval = base_val(num[i], "0123456789abcdef");
		res = res * 16 + hexval;
		i++;
	}
	return (res);
}
