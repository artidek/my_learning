/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:25:15 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/09 23:25:15 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < ' ' || *str > '~')
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
	char *test1 = "Hello, World!"; // All printable
	char *test2 = "Hello\tWorld";  // Contains a tab (non-printable)
	char *test3 = "1234567890";    // All printable
	char *test4 = "\nNew Line";    // Contains a newline (non-printable)
	char *test5 = "Printable!";    // All printable
	char *test6 = "";              // Empty string (considered printable)
	// Running tests
	printf("Test 1: %s -> %d\n", test1, ft_str_is_printable(test1));
		// Expected: 1
	printf("Test 2: %s -> %d\n", test2, ft_str_is_printable(test2));
		// Expected: 0
	printf("Test 3: %s -> %d\n", test3, ft_str_is_printable(test3));
		// Expected: 1
	printf("Test 4: %s -> %d\n", test4, ft_str_is_printable(test4));
		// Expected: 0
	printf("Test 5: %s -> %d\n", test5, ft_str_is_printable(test5));
		// Expected: 1
	printf("Test 6: %s -> %d\n", test6, ft_str_is_printable(test6));
		// Expected: 1
	return (0);
}*/
