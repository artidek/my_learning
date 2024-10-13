/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:05:55 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/13 00:05:55 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	char	c;

	while (*str)
	{
		c = *str;
		write(1, &c, 1);
		str++;
	}
}

/*int main()
{
	ft_putstr("Hello");
	return(0);
}*/