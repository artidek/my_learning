/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:44:12 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/05 16:31:23 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{

}

int	main(void)
{
	char	str[100] = "Learningisfun";

	char *first, *second;
	first = str;
	second = str;
	printf("Original string :%s\n ", str);
	// when overlap it start from first position
	ft_memmove(second + 8, first, 10);
	printf("memmove overlap : %s\n ", str);
	return (0);
}
