/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:08:07 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/09 23:08:07 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
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
	char *test1 = "hello";      // All lowercase
	char *test2 = "Hello";      // Mixed case
	char *test3 = "hello123";   // Lowercase with numbers
	char *test4 = "";            // Empty string
	char *test5 = "abcdef";      // All lowercase
	char *test6 = "abcdeF";      // Lowercase with one uppercase
	char *test7 = "abc def";     // Lowercase with space

	// Running test cases
	printf("Test 1: %s -> %d\n", test1, ft_str_is_lowercase(test1)); // Expect 1
	printf("Test 2: %s -> %d\n", test2, ft_str_is_lowercase(test2)); // Expect 0
	printf("Test 3: %s -> %d\n", test3, ft_str_is_lowercase(test3)); // Expect 0
	printf("Test 4: %s -> %d\n", test4, ft_str_is_lowercase(test4)); // Expect 1
	printf("Test 5: %s -> %d\n", test5, ft_str_is_lowercase(test5)); // Expect 1
	printf("Test 6: %s -> %d\n", test6, ft_str_is_lowercase(test6)); // Expect 0
	printf("Test 7: %s -> %d\n", test7, ft_str_is_lowercase(test7)); // Expect 0

	return (0);
}*/