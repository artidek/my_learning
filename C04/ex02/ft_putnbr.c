/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:40:41 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/13 09:40:41 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	c = '0';
	if (nb < 10 && nb >= 0)
	{
		c = c + nb % 10;
		write(1, &c, 1);
		return ;
	}
	if (nb >= 10)
	{
		c = c + nb % 10;
		ft_putnbr(nb / 10);
		write(1, &c, 1);
	}
	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb = nb * (-1);
		ft_putnbr(nb / 10);
		c = '0' + nb % 10;
		write(1, &c, 1);
	}
}

/*int	main(void)
{
	ft_putnbr(10);
	return (0);
}*/