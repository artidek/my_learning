/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:28:18 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/11 18:28:18 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*comp_str;
	char	*comp_find;

	if (!*to_find)
	{
		return (str);
	}
	while (*str)
	{
		comp_str = str;
		comp_find = to_find;
		while (*comp_str == *comp_find && *comp_find && *comp_str)
		{
			comp_find++;
			comp_str++;
		}
		if (*comp_find == '\0')
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}

/*int	main(void)
{
	// Test cases
	char haystack1[] = "Hello, world!";
	char needle1[] = "world";

	char haystack2[] = "This is a simple test.";
	char needle2[] = "simple";

	char haystack3[] = "Another example string.";
	char needle3[] = "example";

	char haystack4[] = "Edge case with empty needle.";
	char needle4[] = "";

	char haystack5[] = "";
	char needle5[] = "non-empty";

	char haystack6[] = "Substring at the beginning.";
	char needle6[] = "Substring";

	char haystack7[] = "Substring at the end.";
	char needle7[] = "end.";

	char haystack8[] = "No match here.";
	char needle8[] = "absent";

	// Array of test cases
	char *haystacks[] = {haystack1, haystack2, haystack3, haystack4, haystack5,
		haystack6, haystack7, haystack8};
	char *needles[] = {needle1, needle2, needle3, needle4, needle5, needle6,
		needle7, needle8};
	int num_tests = sizeof(haystacks) / sizeof(haystacks[0]);

	int i;
	for (i = 0; i < num_tests; i++)
	{
		char *result_std = strstr(haystacks[i], needles[i]);
		char *result_ft = ft_strstr(haystacks[i], needles[i]);

		// Calculate the position for easier comparison
		int pos_std = result_std ? (int)(result_std - haystacks[i]) : -1;
		int pos_ft = result_ft ? (int)(result_ft - haystacks[i]) : -1;

		// Print test case information
		printf("Test %d:\n", i + 1);
		printf("Haystack: \"%s\"\n", haystacks[i]);
		printf("Needle: \"%s\"\n", needles[i]);

		// Compare results
		if (pos_std == pos_ft)
		{
			printf("Result: PASS (Position %d)\n\n", pos_ft);
		}
		else
		{
			printf("Result: FAIL\n");
			printf("  strstr returned position: %d\n", pos_std);
			printf("  ft_strstr returned position: %d\n\n", pos_ft);
		}
	}

	return (0);
}*/