/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:37:38 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/10 18:37:38 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

static void	to_char(long long int n, int fd)
{
	char	tc;

	tc = '0';
	if (n == 0)
		return ;
	tc += n % 10;
	n = n / 10;
	to_char(n, fd);
	write(fd, &tc, sizeof(char) * 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	tc;

	tc = '0';
	if (n == 0)
	{
		write(fd, &tc + 48, sizeof(char) * 1);
		return ;
	}
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		to_char(-n, fd);
		return ;
	}
	to_char(n, fd);
}