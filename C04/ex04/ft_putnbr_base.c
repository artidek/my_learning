/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:02:46 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/17 13:54:35 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *str)
{
	int		i;
	int		j;
	char	check_c;

	i = 0;
	j = 1;
	while (str[i])
	{
		check_c = str[i];
		while (str[j])
		{
			if (check_c == str[j] || str[j] == '-' || str[j] == '+')
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (i);
}

void	put_nbr(int nbr, char *base, int base_n)
{
	int	num;

	num = nbr;
	if (num < 0)
	{
		if (num == -2147483648 && base_n != 2)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		if ((base_n == 2 && num == -2147483648))
		{
			write(1, "-10000000000000000000000000000000", 33);
			return ;
		}
		write(1, "-", 1);
		num = -num;
	}
	if (num / base_n == 0)
	{
		write(1, &base[num % base_n], 1);
		return ;
	}
	put_nbr(num / base_n, base, base_n);
	write(1, &base[num % base_n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_n;

	base_n = check_base(base);
	if (base_n == 16)
		put_nbr(nbr, base, base_n);
	if (base_n == 10)
		put_nbr(nbr, base, base_n);
	if (base_n == 8)
		put_nbr(nbr, base, base_n);
	if (base_n == 2)
		put_nbr(nbr, base, base_n);
}

/*int	main(void)
{
	ft_putnbr_base(125, "01");
	return (0);
}*/
