/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:41:39 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/08 11:41:39 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*retptr;
	unsigned int	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb * size > UINT_MAX)
	{
		errno = ENOMEM;
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
