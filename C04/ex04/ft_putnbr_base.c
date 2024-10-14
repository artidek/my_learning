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

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	s1_res;
	unsigned char	s2_res;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((s1_res = *s1) - (s2_res = *s2));
}

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
	char	c;


	c = 'A';
	if (n >= 0 && n <= 9)
	{
		ft_putnbr(n);
	}
	else
	{
		c += (n - 10);
		write(1, &c, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	char	c;

	i = 31;
	if (ft_strcmp("0123456789", base) == 0)
		ft_putnbr(nbr);
	if (ft_strcmp("01", base) == 0)
	{
		while (i >= 0)
		{
			ft_putnbr((nbr >> i) & 1);
			i--;
		}
	}
	if (ft_strcmp("0123456789ABCDEF", base) == 0)
	{
		i = 1;
		while (i < 9)
		{
			put_hex((nbr >> (i * 4)) & 0x0F);
			i++;
		}
	}
}

int	main(void)
{
	ft_putnbr_base(156, "0123456789ABCDEF");
	return (0);
}
