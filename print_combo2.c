/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_combo2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:00:00 by aobshatk            #+#    #+#             */
/*   Updated: 2024/10/06 11:00:00 by aobshatk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combo2(void);

int	main(void)
{
	print_combo2();
	return (0);
}

void	put_coma(int a, int b)
{
	if (a == 98 && b == 99)
	{
		return;
	}
	else
	{
		write(1, ", ", 2);
	}
}

void	put_b(int a, int b)
{
	char	num;

	if (b < 9)
	{
		write(1, "0", 1);
		num = '0' + b;
		write(1, &num, 1);
	}
	else if (b % 10 == 0)
	{
		num = '0' + b / 10;
		write(1, &num, 1);
		write(1, "0", 1);
	}
	else
	{
		num = '0' + (b - (b % 10)) / 10;
		write(1, &num, 1);
		num = '0' + b % 10;
		write(1, &num, 1);
	}
	put_coma(a, b);
}

void	put_a(int a, int b)
{
	char	num;

	if (a < 9)
	{
		write(1, "0", 1);
		num = '0' + a;
		write(1, &num, 1);
	}
	else if (a % 10 == 0)
	{
		num = '0' + a / 10;
		write(1, &num, 1);
		write(1, "0", 1);
	}
	else
	{
		num = '0' + (a - (a % 10)) / 10;
		write(1, &num, 1);
		num = '0' + a % 10;
		write(1, &num, 1);
	}
	write(1, " ", 1);
	put_b(a, b);
}

void	print_combo2(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 98)
	{
		j++;
		while (j <= 99)
		{
			put_a(i, j);
			j++;
		}
		i++;
		j = i;
	}
}