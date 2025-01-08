/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:14:02 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/08 23:09:23 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*retptr;
	unsigned int	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (retptr = malloc(sizeof(unsigned char) * 1));
	if (nmemb == INT_MAX || size == INT_MAX || (int)nmemb < 0 || (int)size < 0)
	{
		write(1, "Memory allocation failed: ENOMEM\n", 30);
		return (NULL);
	}
	retptr = malloc(nmemb * size);
	while (i < nmemb * size)
	{
		retptr[i] = 0;
		i++;
	}
	return (retptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	result;

	result = 0;
	while (str[result])
		result++;
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
