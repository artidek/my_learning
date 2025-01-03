/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 07:38:00 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/03 14:07:12 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_char(t_flags flags, char args, t_list *cargs)
{
	int		len;
	char	*result;

	len = 1;
	if ((flags.width > len && flags.minus) || (flags.width > len
			&& !flags.minus))
		len = len + (flags.width - len);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return ;
	if (flags.width > 1 && flags.minus)
	{
		result[0] = (char)args;
		ft_memset(result + 1, ' ', sizeof(char) * len);
	}
	if (flags.width > 1 && !flags.minus)
	{
		ft_memset(result, ' ', sizeof(char) * len - 1);
		result[len - 1] = (char)args;
	}
	if (!flags.width || flags.width == 1)
		result[0] = (char)args;
	result[len] = '\0';
	ft_lstadd_back(&cargs, ft_lstnew(result));
}
