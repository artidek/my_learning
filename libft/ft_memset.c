/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:37:00 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/05 11:35:59 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*ptr;

	ch = c;
	ptr = s;
	while (n > 0)
	{
		*ptr++ = ch;
		n--;
	}
	return (s);
}
