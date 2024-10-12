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

	while (n > 0 && (*s1 && *s2))
	{
		n--;
		s1++;
		s2++;
	}
	return ((s1_res = *s1) - (s2_res = *s2));
}

int	main(void)
{
	char *str1;
	char *str2;

	str1 = "Hello";
	str2 = "HelloWorld";
	printf("Test 1: Comparing  and (n = 4): %d\n", ft_strncmp(str1, str2, 5));
	printf("Test 2: Comparing and (n = 10): %d\n", ft_strncmp(str1, str2, 5));

	return (0);
}