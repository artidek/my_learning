/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:04:26 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/08 13:04:26 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*temdup;
	int		len;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	temdup = dup;
	while (*s)
		*temdup++ = *s++;
	*temdup = '\0';
	return (dup);
}
