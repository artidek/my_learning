/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:12:58 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/11 18:12:58 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, const char *src, unsigned int nb)
{
	char	*r_dest;
	char	*start_cat;

	r_dest = dest;
	while (*dest)
	{
		dest++;
	}
	start_cat = dest;
	while (nb > 0 && *src)
	{
		*(start_cat++) = *(src++);
		nb--;
	}
	*start_cat = '\0';
	return (r_dest);
}

/*int	main(void)
{
	// Test cases
	const char *src;
	const char *dest_initial;
	unsigned int nb;

	// Define an array to hold the results for testing
	char dest_standard[100]; // Buffer for the standard strncat
	char dest_custom[100];   // Buffer for the custom ft_strncat

	// Test case 1
	src = "World!";
	dest_initial = "Hello, ";
	nb = 6;

	strcpy(dest_standard, dest_initial);
	strcpy(dest_custom, dest_initial);
	strncat(dest_standard, src, nb);
	ft_strncat(dest_custom, src, nb);

	printf("Test 1:\n");
	printf("Source: \"%s\"\n", src);
	printf("Destination (initial): \"%s\"\n", dest_initial);
	printf("Standard strncat result: \"%s\"\n", dest_standard);
	printf("Custom ft_strncat result: \"%s\"\n", dest_custom);
	printf("Match: %s\n", strcmp(dest_standard,
			dest_custom) == 0 ? "YES" : "NO");
	printf("---------------------------------------------------\n");

	// Test case 2
	src = "World!";
	dest_initial = "Hello, ";
	nb = 3;

	strcpy(dest_standard, dest_initial);
	strcpy(dest_custom, dest_initial);
	strncat(dest_standard, src, nb);
	ft_strncat(dest_custom, src, nb);

	printf("Test 2:\n");
	printf("Source: \"%s\"\n", src);
	printf("Destination (initial): \"%s\"\n", dest_initial);
	printf("Standard strncat result: \"%s\"\n", dest_standard);
	printf("Custom ft_strncat result: \"%s\"\n", dest_custom);
	printf("Match: %s\n", strcmp(dest_standard,
			dest_custom) == 0 ? "YES" : "NO");
	printf("---------------------------------------------------\n");

	// Test case 3
	src = "12345";
	dest_initial = "ABCDE";
	nb = 10; // nb exceeds src length

	strcpy(dest_standard, dest_initial);
	strcpy(dest_custom, dest_initial);
	strncat(dest_standard, src, nb);
	ft_strncat(dest_custom, src, nb);

	printf("Test 3:\n");
	printf("Source: \"%s\"\n", src);
	printf("Destination (initial): \"%s\"\n", dest_initial);
	printf("Standard strncat result: \"%s\"\n", dest_standard);
	printf("Custom ft_strncat result: \"%s\"\n", dest_custom);
	printf("Match: %s\n", strcmp(dest_standard,
			dest_custom) == 0 ? "YES" : "NO");
	printf("---------------------------------------------------\n");

	// Test case 4
	src = "";
	dest_initial = "No append here";
	nb = 5;

	strcpy(dest_standard, dest_initial);
	strcpy(dest_custom, dest_initial);
	strncat(dest_standard, src, nb);
	ft_strncat(dest_custom, src, nb);

	printf("Test 4:\n");
	printf("Source: \"%s\"\n", src);
	printf("Destination (initial): \"%s\"\n", dest_initial);
	printf("Standard strncat result: \"%s\"\n", dest_standard);
	printf("Custom ft_strncat result: \"%s\"\n", dest_custom);
	printf("Match: %s\n", strcmp(dest_standard,
			dest_custom) == 0 ? "YES" : "NO");
	printf("---------------------------------------------------\n");

	// Test case 5
	src = "Short";
	dest_initial = "This is a ";
	nb = 4;

	strcpy(dest_standard, dest_initial);
	strcpy(dest_custom, dest_initial);
	strncat(dest_standard, src, nb);
	ft_strncat(dest_custom, src, nb);

	printf("Test 5:\n");
	printf("Source: \"%s\"\n", src);
	printf("Destination (initial): \"%s\"\n", dest_initial);
	printf("Standard strncat result: \"%s\"\n", dest_standard);
	printf("Custom ft_strncat result: \"%s\"\n", dest_custom);
	printf("Match: %s\n", strcmp(dest_standard,
			dest_custom) == 0 ? "YES" : "NO");
	printf("---------------------------------------------------\n");

	// Test case 6
	src = "!!";
	dest_initial = "Test";
	nb = 0; // Appending 0 characters

	strcpy(dest_standard, dest_initial);
	strcpy(dest_custom, dest_initial);
	strncat(dest_standard, src, nb);
	ft_strncat(dest_custom, src, nb);

	printf("Test 6:\n");
	printf("Source: \"%s\"\n", src);
	printf("Destination (initial): \"%s\"\n", dest_initial);
	printf("Standard strncat result: \"%s\"\n", dest_standard);
	printf("Custom ft_strncat result: \"%s\"\n", dest_custom);
	printf("Match: %s\n", strcmp(dest_standard,
			dest_custom) == 0 ? "YES" : "NO");
	printf("---------------------------------------------------\n");

	return (0);
}*/