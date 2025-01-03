/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:03:47 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/02 23:12:31 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags)
{
	if (flags.minus)
		flags.zero = 0;
	return (flags);
}

static int	length(char *args, t_flags flags)
{
	int	len;

	len = (int)ft_strlen(args);
	if (flags.hash)
		len += 2;
	if (flags.width > len)
		len = len + (flags.width - len);
	return (len);
}

void	ft_print_x(t_flags flags, unsigned int args, t_list *cargs)
{
	int		len;
	char	*sargs;
	char	*result;
	t_flags	o_flags;

	o_flags = override_flags(flags);
	sargs = ft_btoa((unsigned int)args, "0123456789abcdef");
	len = length(sargs, o_flags);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return ;
	if (len > (int)ft_strlen((sargs)))
	{
		ft_print_hex(o_flags, len + 1, &result, sargs);
		ft_lstadd_back(&cargs, ft_lstnew(result - len));
	}
	else
	{
		ft_strlcpy(result, sargs, len + 1);
		ft_lstadd_back(&cargs, ft_lstnew(result));
	}
	free(sargs);
}
