/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:19:04 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/06 23:19:04 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char ch;

	ch = c;
	while (*(unsigned char *)s && n > 0)
	{
		if (*(unsigned char *)s == ch)
			return ((unsigned char *)s);
		s++;
		n--;
	}
	return (NULL);
}