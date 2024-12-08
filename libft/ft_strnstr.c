/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:45:36 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/07 18:45:36 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*tempn;
	const char	*temph;
	size_t		i;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		tempn = needle;
		temph = haystack;
		i = len;
		while (*tempn == *temph && i > 0)
		{
			i--;
			tempn++;
			temph++;
		}
		if (i == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
