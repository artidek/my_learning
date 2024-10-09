/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:27:02 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/09 20:27:02 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*r_dest;
	unsigned int	i;

	i = 0;
	r_dest = dest;
	while (*src != 0 && i < n)
	{
		*(dest++) = *(src++);
		i++;
	}
	while (i < n)
	{
		*(dest++) = '\0';
		i++;
	}
	return (r_dest);
}

/*int	main(void)
{
	char	test1[6] = "World1";

	ft_strncpy(test1, "Hello", 5);

	printf("%s\n", test1);

	return (0);
}*/