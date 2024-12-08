/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:50:38 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/08 13:50:38 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*temp;

	substr = malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	temp = substr;
	while (s[start] && len > 0)
	{
		*temp++ = s[start];
		len--;
		start++;
	}
	*temp = '\0';
	return (substr);
}