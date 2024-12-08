/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:42:54 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/06 21:42:54 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strrchr(const char *str, int ch)
{
	char	*retptr;
	char	chr;

	chr = ch;
	retptr = NULL;
	while (*str)
	{
		if (*str == chr)
			retptr = (char *)str;
		str++;
	}
	return (retptr);
}
