/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:49:26 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/17 13:54:53 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	put_sign(int res, int sign)
{
	if (sign % 2 != 0)
	{
		return (res * -1);
	}
	return (res);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 0;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r')
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign++;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result = put_sign(result, sign);
	return (result);
}

/*int	main(void)
{
	//int print_it;

	//print_it = ft_atoi(argv[1]);
	//printf("%d", print_it);
	return (0);
}*/
