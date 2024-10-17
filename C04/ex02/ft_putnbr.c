/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:40:41 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/17 13:21:21 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;
	int		num;

	num = nb;
	if (num < 0)
	{
		if (num == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		num = -num;
	}
	if (num / 10 == 0)
	{
		c = '0' + num % 10;
		write(1, &c, 1);
		return ;
	}
	ft_putnbr(num / 10);
	c = '0' + num % 10;
	write(1, &c, 1);
}

/*int	main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}*/
