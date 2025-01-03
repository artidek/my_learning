/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:56:52 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/03 12:08:36 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	override_flags(t_flags flags)
{
	flags.hash = 1;
	flags.zero = 0;
	return (flags);
}

static void	print_null(char *result, t_list *cargs, t_flags flags, int size)
{
	int	i;

	i = size - 6;
	if (i > 0)
	{
		if (!flags.minus)
		{
			ft_memset(result, ' ', i);
			ft_memmove(result + i, "(nil)", sizeof(char) * 5);
		}
		else
		{
			ft_memmove(result, "(nil)", sizeof(char) * 5);
			ft_memset(result + 5, ' ', i);
		}
		result[size] = '\0';
		ft_lstadd_back(&cargs, ft_lstnew(result));
	}
	else
	{
		ft_strlcpy(result, "(nil)", size);
		ft_lstadd_back(&cargs, ft_lstnew(result));
	}
}

static int	length(char *args, t_flags flags)
{
	int	len;

	len = (int)ft_strlen(args);
	if (ft_strncmp(args, "(nil)", 5))
		len += 2;
	if (flags.width > len)
		len = len + (flags.width - len);
	return (len);
}

static void	set_str(t_flags flags, int size, char **result, char *args)
{
	size = size - (int)ft_strlen((char *)args) - 3;
	if (!flags.minus)
	{
		while (size-- > 0)
			*(*result)++ = ' ';
	}
	*(*result)++ = '0';
	*(*result)++ = 'x';
	while (*args)
	{
		*(*result)++ = *args++;
	}
	while (size-- > 0 && flags.minus)
		*(*result)++ = ' ';
	**result = '\0';
}

void	ft_print_pointer(t_flags flags, void *args, t_list *cargs)
{
	int		len;
	t_flags	o_flags;
	char	*result;
	char	*sargs;

	o_flags = override_flags(flags);
	if ((long long unsigned int)args == 0)
	{
		result = malloc(sizeof(char) * length("(nil)", o_flags) + 1);
		if (!result)
			return ;
		print_null(result, cargs, o_flags, length("(nil)", o_flags) + 1);
	}
	else
	{
		sargs = ft_btoa((long long unsigned int)args, "0123456789abcdef");
		len = length(sargs, o_flags);
		result = malloc(sizeof(char) * len + 1);
		if (!result)
			return ;
		set_str(o_flags, len + 1, &result, sargs);
		ft_lstadd_back(&cargs, ft_lstnew(result - len));
		free(sargs);
	}
}
