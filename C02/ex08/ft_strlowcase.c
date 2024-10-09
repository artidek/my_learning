/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:32:17 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/10 00:32:17 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*r_str;

	r_str = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str + 32;
		}
		str++;
	}
	return (r_str);
}

/*int	main(void)
{
	char str[] = "HeLLo WoRLd!";
	printf("Original string: %s\n", str);  // Print the original string
	ft_strlowcase(str);
		// Call the function to convert to lowercase
	printf("Lowercase string: %s\n", str); // Print the modified string
	return (0);                              // Exit the program
}*/