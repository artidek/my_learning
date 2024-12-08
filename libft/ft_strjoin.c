/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:12:36 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/08 14:12:36 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	printf("%d\n", i);
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	char	*temp;
	int		len;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	printf("%d\n", len);
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
