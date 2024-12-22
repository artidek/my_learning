/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:45:36 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/16 11:14:20 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*temph;
	size_t		i;
	size_t		a;

	a = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	if ((int)len < 0)
		len = ft_strlen((char *)haystack);
	if (len > 1)
		len = len - 1;
	while (a < len && haystack[a])
	{
		i = 0;
		temph = &haystack[a];
		while (i < ft_strlen((char *)needle) && (needle[i] == temph[i]))
			i++;
		if (i == ft_strlen((char *)needle))
			return ((char *)&haystack[a]);
		a++;
	}
	return (NULL);
}
