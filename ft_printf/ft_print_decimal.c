/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:15:52 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/02 12:57:05 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags, char *conv)
{
	if (flags.minus)
		flags.zero = 0;
	if (flags.plus)
		flags.blank = 0;
	if (conv[0] == '-')
	{
		flags.blank = 0;
		flags.plus = 0;
	}
	return (flags);
}

static int	length(char *args, t_flags flags)
{
	int	len;

	len = (int)ft_strlen(args);
	if ((flags.plus || flags.blank) && flags.width > len)
		len++;
	if (flags.width > len)
		len = len + (flags.width - len);
	return (len);
}

static void	set_str(t_flags flags, char **result, void *args, int sz)
{
	sz = sz - (int)ft_strlen(args);
	if (flags.blank)
		*(*result)++ = ' ';
	if (flags.plus)
		*(*result)++ = '+';
	if (flags.zero || !flags.minus)
	{
		while (sz-- > 0)
		{
			if (flags.zero)
				*(*result)++ = '0';
			else
				*(*result)++ = ' ';
		}
		while (*(char *)args)
			*(*result)++ = *(char *)args++;
	}
	if (flags.minus)
	{
		while (*(char *)args)
			*(*result)++ = *(char *)args++;
		while (sz-- > 0)
			*(*result)++ = ' ';
	}
}

void	ft_print_decimal(t_flags flags, int args, t_list *cargs)
{
	int		len;
	char	*conv;
	char	*result;
	t_flags	o_flags;

	conv = ft_itoa((int)args);
	o_flags = override_flags(flags, conv);
	len = (length(conv, o_flags));
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return ;
	if (len > (int)ft_strlen(conv))
	{
		set_str(o_flags, &result, conv, len);
		*result = '\0';
		ft_lstadd_back(&cargs, ft_lstnew(result - len));
	}
	if (len <= (int)ft_strlen(conv))
	{
		ft_strlcpy(result, conv, len + 1);
		ft_lstadd_back(&cargs, ft_lstnew(result));
	}
	free(conv);
}
