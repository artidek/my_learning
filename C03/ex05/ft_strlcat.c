/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:51:48 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/12 19:51:48 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

int	ft_strlen(char *str)
{
	int		len;
	char	c;

	len = 0;
	c = *str;
	while (c != '\0')
	{
		len++;
		str++;
		c = *str;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*r_dest;
	char			*start_cat;
	unsigned int	dest_len;
	unsigned int	buffer;
	unsigned int	src_len;

	r_dest = dest;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	while (*dest)
	{
		dest++;
	}
	start_cat = dest;
	buffer = size - dest_len - 1;
	while (buffer > 0 && *src)
	{
		*(start_cat++) = *(src++);
		buffer--;
	}
	*start_cat = '\0';
	return (src_len + dest_len);
}

/*int	main(void)
{
	// Test case variables
	char dst[20]; // Destination buffer
	char *src = "world";

	// Test case 1: Basic concatenation
	strcpy(dst, "Hello");
	size_t result = ft_strlcat(dst, src, sizeof(dst));
	printf("Test 1 - Expected: HelloWorld Got: %s Result: %zu\n", dst, result);

	// Test case 2: Destination buffer is too small
	strcpy(dst, "Hello");
	result = ft_strlcat(dst, src, 10);
	printf("Test 2 - Expected: HelloWorl Got: %s Result: %zu\n", dst, result);

	// Test case 3: Empty destination
	strcpy(dst, "");
	result = ft_strlcat(dst, src, sizeof(dst));
	printf("Test 3 - Expected: world Got: %s Result: %zu\n", dst, result);

	// Test case 4: Empty source
	strcpy(dst, "Hello");
	result = ft_strlcat(dst, "", sizeof(dst));
	printf("Test 4 - Expected: Hello Got: %s Result: %zu\n", dst, result);

	// Test case 5: Large source string
	strcpy(dst, "Hello");
	char *large_src = "this is a really long string that won't fit";
	result = ft_strlcat(dst, large_src, sizeof(dst));
	printf("Test 5 - Expected: Hellothis is a real Got: %s Result: %zu\n", dst,
		result);

	// Test case 6: Size exactly equal to destination length
	strcpy(dst, "Hello");
	result = ft_strlcat(dst, src, 5);
	printf("Test 6 - Expected: Hello Got: %s Result: %zu\n", dst, result);

	// Test case 7: Size equal to destination length + 1
	strcpy(dst, "Hello");
	result = ft_strlcat(dst, src, 6);
	printf("Test 7 - Expected: Hello Got: %s Result: %zu\n", dst, result);

	// Test case 8: Size 0
	strcpy(dst, "Hello");
	result = ft_strlcat(dst, src, 0);
	printf("Test 8 - Expected: Hello Got: %s Result: %zu\n", dst, result);

	// Test case 9: Large size
	strcpy(dst, "Hello");
	result = ft_strlcat(dst, src, 100);
	printf("Test 9 - Expected: HelloWorld Got: %s, Result: %zu\n", dst, result);

	return (0);
}*/