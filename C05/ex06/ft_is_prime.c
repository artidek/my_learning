/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:19:54 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/19 11:50:45 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	int	check_num;

	check_num = nb - 2;
	if (nb <= 1)
		return (0);
	while (check_num > 0)
	{
		if (nb % check_num == 0 && check_num != 1)
			return (0);
		check_num -= 2;
	}
	return (1);
}

/*int	main(int argc, char *argv[])
{
	int result = ft_is_prime(atoi(argv[1]));
	printf("%d\n", result);
	return(0);
}*/
