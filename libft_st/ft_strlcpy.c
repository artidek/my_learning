/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:57:40 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/18 16:02:07 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;
	int	len;
	int	sz;

	i = 0;
	len = 0;
	sz = (int)size;
	while (src[len])
		len++;
	if (sz < 0)
		sz = len + 1;
	while (i < sz - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (sz > 0)
		dst[i] = '\0';
	return (len);
}
