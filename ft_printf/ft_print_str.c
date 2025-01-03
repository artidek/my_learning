/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:19:41 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/03 09:54:54 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*alloc_mem(int sz)
{
	char	*result;

	result = malloc(sizeof(char) * sz + 1);
	if (!result)
		return (NULL);
	return (result);
}

static void	print_null(char *result, t_list *cargs, t_flags flags, int size)
{
	int	i;

	i = size - 7;
	if (i > 0)
	{
		if (!flags.minus)
		{
			ft_memset(result, ' ', i);
			ft_memmove(result + i, "(null)", sizeof(char) * 5);
		}
		else
		{
			ft_memmove(result, "(null)", sizeof(char) * 5);
			ft_memset(result + 5, ' ', i);
		}
		result[size] = '\0';
		ft_lstadd_back(&cargs, ft_lstnew(result));
	}
	else
	{
		ft_strlcpy(result, "(null)", size);
		ft_lstadd_back(&cargs, ft_lstnew(result));
	}
}

static int	size(t_flags flags, void *args)
{
	int	len;

	len = (int)ft_strlen((char *)args);
	if (flags.minus && flags.width > len)
		len = len + (flags.width - len);
	if (!flags.minus && flags.width > len)
		len = len + (flags.width - len);
	return (len);
}

static void	set_str(t_flags flags, char **result, void *args, int sz)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen((char *)args);
	if (!flags.minus)
	{
		while (i++ < flags.width - len)
			*(*result)++ = ' ';
		while (i++ < sz)
			*(*result)++ = *(char *)args++;
	}
	if (flags.minus)
	{
		while (i++ < len)
			*(*result)++ = *(char *)args++;
		while (i++ < sz)
			*(*result)++ = ' ';
	}
	(*result)++;
	**result = '\0';
}

void	ft_print_str(t_flags flags, void *args, t_list *cargs)
{
	int		len;
	char	*result;

	if (!args)
	{
		len = size(flags, "(null)");
		result = alloc_mem(len);
		if (result)
			print_null(result, cargs, flags, len + 1);
		return ;
	}
	len = size(flags, args);
	result = alloc_mem(len);
	if (flags.width > (int)ft_strlen((char *)args) && result)
	{
		len += 1;
		set_str(flags, &result, args, len);
		ft_lstadd_back(&cargs, ft_lstnew(result - len));
	}
	if (flags.width <= (int)ft_strlen((char *)args) && result)
	{
		ft_strlcpy(result, (char *)args, len + 1);
		ft_lstadd_back(&cargs, ft_lstnew(result));
	}
}
