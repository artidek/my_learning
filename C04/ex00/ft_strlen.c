/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:40:09 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/12 23:40:09 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
	{
		i++;
	}
	return (i);
}

/*int main() {
	// Test cases
	struct {
		char* input_string;
		int expected;
	} test_cases[] = {
		{"hello", 5},            // Case 1: Normal string
		{"", 0},                 // Case 2: Empty string
		{"OpenAI", 6},           // Case 3: String with mixed case
		{"123456", 6},           // Case 4: String with numbers
		{" ", 1},                // Case 5: String with a single space
		{"!@#", 3}               // Case 6: String with special characters
	};

	// Number of test cases
	int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	// Running the test cases
	for (int i = 0; i < num_tests; i++) {
		char* input_string = test_cases[i].input_string;
		int expected = test_cases[i].expected;
		int result = ft_strlen(input_string);

		if (result == expected) {
			printf("Test case %d passed!\n", i + 1);
		} else {
			printf("Test case %d failed! Expected %d but got %d\n", i + 1,
				expected, result);
		}
	}

	return (0);
}*/