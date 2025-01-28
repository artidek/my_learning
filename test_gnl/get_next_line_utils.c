/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:49:03 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/28 20:23:33 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	result;

	result = 0;
	while (str[result])
		result++;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	char	*temp;
	int		len;
	int		len_s1;
	int		len_s2;

	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	len = len_s1 + len_s2;
	jstr = malloc(sizeof(char) * len + 1);
	if (jstr == NULL)
		return (NULL);
	temp = jstr;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (jstr);
}

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
		write(1, "Memory allocation failed: ENOMEM\n", 30);
		return (NULL);
	}
	temdup = dup;
	while (*s)
		*temdup++ = *s++;
	*temdup = '\0';
	return (dup);
}

char	*ft_strchr(const char *str, int ch)
{
	char	cmp;

	cmp = ch;
	while (*str)
	{
		if (*str == cmp)
			return ((char *)str);
		str++;
	}
	if (*str == ch)
		return ((char *)str);
	return (NULL);
}
