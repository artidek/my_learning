/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:42:28 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/15 11:43:37 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*ptr;

	ch = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr++ = ch;
		n--;
	}
	return (s);
}

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;
	size_t				i;

	ptr = (unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	i = 0;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (s1);
}

char	*realloc_str(char *str, int size)
{
	char	*temp;

	temp = malloc(size);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, str, size);
	return (temp);
}
