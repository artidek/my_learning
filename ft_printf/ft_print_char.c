/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 07:38:00 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/06 20:33:45 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags)
{
	if (flags.width > 0)
		flags.width -= 1;
	return (flags);
}

static int	size(t_flags flags)
{
	int	len;
	int	sz;

	len = 1;
	sz = len;
	if (flags.width > 0)
		sz = len + flags.width;
	return (sz);
}

void	ft_print_char(t_flags flags, char args, t_list *cargs)
{
	t_flags	o_flags;
	char	*result;
	char *temp;

	o_flags = override_flags(flags);
	result = calloc(sizeof(char), sizeof(char) * size(o_flags) + 1);
	if (!result)
		return;
	if (!o_flags.width)
		result[0] = (char)args;
	temp = result;
	if (o_flags.width && !flags.minus)
	{
		memset(result, ' ', size(o_flags) - 1);
		temp += (size(o_flags) - 1);
		*temp = (char)args;
	}
	if (o_flags.width && o_flags.minus)
	{
		temp[0] = (char)args;
		temp++;
		memset(temp, ' ', size(o_flags) - 1);
	}
	ft_lstadd_back(&cargs, ft_lstnew(result));
}
