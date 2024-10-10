/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:10:41 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/10 18:31:57 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	s1_res;
	unsigned char	s2_res;

	if (n > 0)
	{
		while ((n > 0 && (*s1 == *s2)) || *s1 != '\0')
		{
			s1++;
			s2++;
			n--;
		}
		return ((s1_res = *s1) - (s2_res = *s2));
	}
	return (0);
}

/*int main() {
	char *test1_a = "hello";
	char *test1_b = "hello";
	unsigned int n1 = 5;

	char *test2_a = "hello";
	char *test2_b = "hella";
	unsigned int n2 = 5;

	char *test3_a = "hello";
	char *test3_b = "helloo";
	unsigned int n3 = 5;

	char *test4_a = "hello";
	char *test4_b = "world";
	unsigned int n4 = 3;

	char *test5_a = "abc";
	char *test5_b = "abcde";
	unsigned int n5 = 5;

	// Test cases
	printf("Test 1: %d\n", ft_strncmp(test1_a, test1_b, n1)); // Expected: 0
	printf("Test 2: %d\n", ft_strncmp(test2_a, test2_b, n2));
		// Expected: > 0 (positive)
	printf("Test 3: %d\n", ft_strncmp(test3_a, test3_b, n3));
		// Expected: < 0 (negative)
	printf("Test 4: %d\n", ft_strncmp(test4_a, test4_b, n4));
		// Expected: < 0 (negative)
	printf("Test 5: %d\n", ft_strncmp(test5_a, test5_b, n5)); // Expected: 0

	return (0);
}*/
