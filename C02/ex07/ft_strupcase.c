/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:36:49 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/09 23:36:49 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*r_str;

	r_str = str;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - 32;
		}
		str++;
	}
	return (r_str);
}

/*int	main(void)
{
	char str[] = "Hello, World! This is a Test String!]";
	// printf("Original String: %s\n", str);
	char *res = ft_strupcase(str);
	printf("Uppercase String: %s\n", res);
	return (0);
}*/