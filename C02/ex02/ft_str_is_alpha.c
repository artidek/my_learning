/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:34:05 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/09 21:34:05 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/*int	main(void)
{
	printf("%d\n", ft_str_is_alpha("Hello"));
		// Expected: 1
	printf("%d\n", ft_str_is_alpha("Hello123"));
		// Expected: 0
	printf("%d\n", ft_str_is_alpha("123"));
		// Expected: 0
	printf("%d\n", ft_str_is_alpha(""));
		// Expected: 1
	printf("%d\n", ft_str_is_alpha("Hello World"));
		// Expected: 0
	printf("%d\n", ft_str_is_alpha("abcdefghijklmnopqrstuvwxyz"));
		// Expected: 1
	printf("%d\n", ft_str_is_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
		// Expected: 1
	return (0);
}*/
