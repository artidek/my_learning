/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:24:41 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/05 12:51:51 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = s1;
	ptr2 = s2;
	while (n > 0)
	{
		*ptr++ = *ptr2++;
		n--;
	}
	return (s1);
}
