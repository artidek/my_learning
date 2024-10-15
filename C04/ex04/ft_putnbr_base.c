/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:02:46 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/14 19:51:59 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

void	put_hex(int n)
{
	char	*to_char;

	to_char = "0123456789ABCDEF";
	if (n < 1)
		return ;
	put_hex(n / 16);
	write(1, &to_char[n % 16], 1);
}

void	put_bit(unsigned int n)
{
	bool zero_fl;
	char prt_bt;
	int count;

	zero_fl = false;
	count = 0;
	n = (n >> 28) & 0x0F;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (*s1)
		a += *(s1++);
	while (*s2)
		b += *(s2++);
	if (a == b)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_strcmp("0123456789", base) == 0)
		ft_putnbr(nbr);
	if (ft_strcmp("01", base) == 0)
	{
		if (nbr == 0)
			write(1, "0", 1);
		put_bit(nbr);
	}
	if (ft_strcmp("0123456789ABCDEF", base) == 0)
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
			put_hex(nbr);
		}
	if (ft_strcmp("poneyvif", base) == 0)
	{
		if (nbr == 0)
		{
			return ;
		}
		ft_putnbr_base(nbr / 8, base);
		ft_putnbr(nbr % 8);
	}
}

int	main(void)
{
	ft_putnbr_base(512, "0123456789");
	return (0);
}
