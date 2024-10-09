/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:55:02 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/09 22:55:02 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/*int main()
{
	// Test cases
	char *test1 = "12345";       // Should return 1
	char *test2 = "123a5";      // Should return 0
	char *test3 = "";            // Should return 1 (empty string)
	char *test4 = "1234567890";  // Should return 1
	char *test5 = "1.234";       // Should return 0

	printf("Test 1: %s -> %d\n", test1, ft_str_is_numeric(test1));
	printf("Test 2: %s -> %d\n", test2, ft_str_is_numeric(test2));
	printf("Test 3: %s -> %d\n", test3, ft_str_is_numeric(test3));
	printf("Test 4: %s -> %d\n", test4, ft_str_is_numeric(test4));
	printf("Test 5: %s -> %d\n", test5, ft_str_is_numeric(test5));

	return (0);
}*/