/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:04:26 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/15 14:20:47 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	int		sz;
	int		i;

	dlen = ft_strlen((char *)dst);
	slen = ft_strlen((char *)src);
	sz = (int)size - (int)dlen - 1;
	i = 0;
	if ((int)size < 0)
		sz = (int)slen + 1;
	if (slen == 0)
		return (dlen);
	if (size == 0)
		return (slen);
	while (i < sz)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	if (size <= dlen)
		return (slen + (int)size);
	dst[(int)ft_strlen(dst) + i] = '\0';
	return (slen + dlen);
}
