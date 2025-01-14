/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:49:03 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/13 23:35:42 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
void	*ft_memcpy(void *restrict s1, const void *restrict s2, size_t n)
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

int length(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	realloc_str(char ***str, int size)
{
	char	*temp;
	char	*cp;

	temp = malloc(sizeof(char) * size);
	if (!temp)
		return (0);
	ft_memset(temp, 0, size);
	cp = **str;
	ft_memcpy(temp, cp, size);
	free(**str);
	**str = malloc(sizeof(char) * (size * 2));
	if (!**str)
		return (0);
	ft_memset(**str, 0, size);
	ft_memcpy(**str,temp, size);
	free(temp);
	return (size * 2);
}
