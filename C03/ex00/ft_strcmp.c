/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:40:56 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/10 18:11:00 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	s1_res;
	unsigned char	s2_res;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((s1_res = *s1) - (s2_res = *s2));
}

/*int	main(void)
{
	// Test cases
	//printf("Test 1: %d (Expected: 0)\n", ft_strcmp("hello", "hello"));
	// s1 longer than s2
	//printf("Test 4: %d (Expected: 32)\n", ft_strcmp("abc", "ABC"));
	// Different case
	//printf("Test 5: %d (Expected: 0)\n", ft_strcmp("", ""));
	// Both empty
	//printf("Test 6: %d (Expected: -1)\n", ft_strcmp("", "non-empty"));
	// s1 empty, s2 not
	//printf("Test 7: %d (Expected: 1)\n", ft_strcmp("non-empty", ""));
	// s1 not empty, s2 empty
	return (0);
}*/
