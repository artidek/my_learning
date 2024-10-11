/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:32:53 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/11 17:32:53 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*r_dest;
	char	*start_cat;

	r_dest = dest;
	while (*dest)
	{
		dest++;
	}
	start_cat = dest;
	while (*src)
	{
		*(start_cat++) = *(src++);
	}
	*start_cat = '\0';
	return (r_dest);
}

/*int	main(void)
{
	char	dest1[100];
	char	dest2[100];

	// Buffer sizes to avoid overflow
	// Test case 1: Normal concatenation
	strcpy(dest1, "Hello, ");
	strcpy(dest2, "Hello, ");
	printf("Original src: \"World!\"\n");
	printf("Standard strcat: \"%s\"\n", strcat(dest1, "World!"));
	printf("Custom ft_strcat: \"%s\"\n\n", ft_strcat(dest2, "World!"));
	// Test case 2: Empty source string
	strcpy(dest1, "Test");
	strcpy(dest2, "Test");
	printf("Original src: \"\"\n");
	printf("Standard strcat: \"%s\"\n", strcat(dest1, ""));
	printf("Custom ft_strcat: \"%s\"\n\n", ft_strcat(dest2, ""));
	// Test case 3: Empty destination string
	strcpy(dest1, "");
	strcpy(dest2, "");
	printf("Original src: \"Test\"\n");
	printf("Standard strcat: \"%s\"\n", strcat(dest1, "Test"));
	printf("Custom ft_strcat: \"%s\"\n\n", ft_strcat(dest2, "Test"));
	// Test case 4: Special characters
	strcpy(dest1, "Special: ");
	strcpy(dest2, "Special: ");
	printf("Original src: \"123!@#\"\n");
	printf("Standard strcat: \"%s\"\n", strcat(dest1, "123!@#"));
	printf("Custom ft_strcat: \"%s\"\n\n", ft_strcat(dest2, "123!@#"));
	// Test case 5: Long strings
	strcpy(dest1, "Long: ");
	strcpy(dest2, "Long: ");
	printf("Original src: \
	"This is a very long string to test strcat behavior.\"\n");
	printf("Standard strcat: \"%s\"\n", strcat(dest1,
			"This is a very long string to test strcat behavior."));
	printf("Custom ft_strcat: \"%s\"\n\n", ft_strcat(dest2,
			"This is a very long string to test strcat behavior."));
	return (0);
}*/
