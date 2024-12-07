/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:21:27 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/06 21:21:27 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *ft_strchr(const char *str, int ch)
{
	char cmp;

	cmp = ch;
	while(*str)
	{
		if (*str == cmp)
			return ((char *)str);
		str++;
	}
	return(NULL);
}
