/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:51:56 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/17 19:12:41 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	unsigned int	fib;
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 1;
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index < 0)
		return (-1);
	while (index - 1)
	{
		fib = a + b;
		a = b;
		b = fib;
		index--;
	}
	return (fib);
}
/*int	main(void)
{
	int	res;

	res = ft_fibonacci(7);
	printf("%d", res);
	return (0);
}*/
