/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:49:36 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/07 23:49:36 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int		len;
	char	c;

	len = 0;
	c = *str;
	while (c != '\0')
	{
		len++;
		c = *str++;
	}
	return (len - 1);
}
