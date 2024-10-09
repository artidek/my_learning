/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:16:46 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/09 23:16:46 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/*int	main(void)
{
	// Test cases
	char *test1 = "HELLO";        // Only uppercase
	char *test2 = "Hello";        // Mixed case
	char *test3 = "WORLD!";       // Contains a non-uppercase character
	char *test4 = "/Ltioe ;'957"; // Different characters
	char *test5 = "ABCDEF";       // Only uppercase

	// Testing the function
	printf("Test 1: \"%s\" -> %d\n", test1, ft_str_is_uppercase(test1));
	// Expected: 1
	printf("Test 2: \"%s\" -> %d\n", test2, ft_str_is_uppercase(test2));
	// Expected: 0
	printf("Test 3: \"%s\" -> %d\n", test3, ft_str_is_uppercase(test3));
	// Expected: 0
	printf("Test 4: \"%s\" -> %d\n", test4, ft_str_is_uppercase(test4));
	// Expected: 1
	printf("Test 5: \"%s\" -> %d\n", test5, ft_str_is_uppercase(test5));
	// Expected: 1

	return (0);
}*/