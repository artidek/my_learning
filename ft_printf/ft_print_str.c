/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:19:41 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/06 16:18:12 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags, char *conv)
{
	if (*conv == '\0')
	{
		flags.width = 0;
		flags.msize = 0;
		return (flags);
	}
	if (flags.msize < 0)
		flags.width -= (int)ft_strlen(conv);
	if (flags.msize > (int)ft_strlen(conv))
		flags.msize = (int)ft_strlen(conv);
	if (flags.width >= 0 && flags.msize >= 0)
		flags.width -= flags.msize;
	if (flags.width < 0)
		flags.width = 0;
	return (flags);
}

static int	size(char *args, t_flags flags)
{
	int	len;
	int	sz;

	len = (int)ft_strlen(args);
	if (flags.msize < len && !(flags.msize < 0))
		len = flags.msize;
	sz = len;
	if (flags.width > 0)
		sz = len + flags.width;
	if (flags.msize < 0)
		flags.msize = 0;
	return (sz);
}

static void	set_args_te(t_flags flags, char *args, t_list *cargs)
{
	int		sz;
	char	*result;
	char	*temp;

	sz = size(args, flags);
	result = ft_calloc(sizeof(char), sizeof(char) * sz + 1);
	if (!result)
		return ;
	temp = result;
	if (sz + 1 == 1)
	{
		ft_lstadd_back(&cargs, ft_lstnew(result));
		return ;
	}
	memmove(temp, args, sz - flags.width);
	temp += (sz - flags.width);
	if (flags.width > 0)
	{
		memset(temp, ' ', flags.width);
		temp += flags.width;
	}
	ft_lstadd_back(&cargs, ft_lstnew(result));
}

static void	set_args_fs(t_flags flags, char *args, t_list *cargs)
{
	int		sz;
	char	*result;
	char	*temp;

	sz = size(args, flags);
	result = ft_calloc(sizeof(char), sizeof(char) * sz + 1);
	if (!result)
		return ;
	temp = result;
	if (sz + 1 == 1)
	{
		ft_lstadd_back(&cargs, ft_lstnew(result));
		return ;
	}
	if (flags.width > 0)
	{
		memset(temp, ' ', flags.width);
		temp += flags.width;
	}
	memmove(temp, args, sz - flags.width);
	ft_lstadd_back(&cargs, ft_lstnew(result));
}

void	ft_print_str(t_flags flags, void *args, t_list *cargs)
{
	char	*sargs;
	t_flags	o_flags;

	sargs = (char *)args;
	if ((!sargs && flags.msize >= (int)ft_strlen("(null)")) || (!sargs
			&& flags.msize < 0))
		sargs = "(null)";
	if (!sargs && flags.msize < (int)ft_strlen("(null)") && flags.msize >= 0)
		sargs = "\0";
	o_flags = override_flags(flags, sargs);
	if (flags.minus)
		set_args_te(o_flags, sargs, cargs);
	else
		set_args_fs(o_flags, sargs, cargs);
}
