/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:52:59 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/17 20:52:59 by aobshatk         ###   ########.fr       */
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
	b = 2;
	if(nb == 1)
		return(1);
	while (b < nb)
	{
		printf("%d\n", b);
		if (a % b == 0)
		{
			result = a / b;
			a = result;
		}
		else
		{
			b += 1;
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