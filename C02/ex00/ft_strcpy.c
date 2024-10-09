/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:52:50 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/08 20:52:50 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*rt_dest;

	rt_dest = dest;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (rt_dest);
}

/*int	main(void)
{
	char	dest[10];
	char	*result;

	result = ft_strcpy(dest, "Hello");
	printf("%s\n", result);
	return (0);
}*/
