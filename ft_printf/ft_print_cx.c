/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:00:31 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/02 20:38:47 by aobshatk         ###   ########.fr       */
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

static void	print_prefix(t_flags flags, int size, char **result, char *args)
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
		*(*result)++ = 'X';
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

void	ft_print_cx(t_flags flags, unsigned int args, t_list *cargs)
{
	int		len;
	char	*sargs;
	char	*result;
	t_flags	o_flags;

	o_flags = override_flags(flags);
	sargs = ft_btoa((unsigned int)args, "0123456789ABCDEF");
	len = length(sargs, o_flags);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return ;
	if (len > (int)ft_strlen((sargs)))
	{
		print_prefix(o_flags, len + 1, &result, sargs);
		ft_lstadd_back(&cargs, ft_lstnew(result - len));
	}
	else
	{
		ft_strlcpy(result, sargs, len + 1);
		ft_lstadd_back(&cargs, ft_lstnew(result));
	}
	free(sargs);
}
