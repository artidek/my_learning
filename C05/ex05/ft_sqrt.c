/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:52:59 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/19 11:56:27 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	a;
	int	b;
	int	result;

	a = nb;
	b = nb - 2;
	if (nb == 1)
		return (1);
	while (b > 1)
	{
		if (a % b == 0)
		{
			result = a / b;
			a = result;
		}
		else
		{
			b -= 2;
			a = nb;
		}
		if (result == 1)
			return (b);
	}
	return (0);
}
/*int	main(int argc, char *argv[])
{
	int result = ft_sqrt(atoi(argv[1]));

	printf("returned %d", result);

	return (0);
}*/
