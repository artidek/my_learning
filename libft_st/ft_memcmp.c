/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:42:01 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/18 16:00:29 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
		{
			if (*(unsigned char *)s1 - *(unsigned char *)s2 > 0)
				return (1);
			if (*(unsigned char *)s1 - *(unsigned char *)s2 < 0)
				return (-1);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
