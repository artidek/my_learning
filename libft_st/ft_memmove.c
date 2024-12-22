/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:44:12 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/18 16:00:43 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overlap(char *s1, const char *s2, int size)
{
	const char	*temp;
	int			i;
	int			a;

	temp = s2;
	i = size;
	a = size;
	while (i > 0 && *s1)
	{
		while (a > 0 && *s2)
		{
			if (s1 == temp)
			{
				return (1);
			}
			a--;
			temp++;
		}
		temp = s2;
		a = size;
		s1++;
		i--;
	}
	return (0);
}

static void	overlap_move(char *s1, const char *s2, int size)
{
	int			i;
	char		*ptr;
	const char	*ptr2;

	i = size;
	ptr = s1;
	ptr2 = s2;
	while (i > size - 1)
	{
		ptr++;
		ptr2++;
		i--;
	}
	i = size;
	while (i > 0)
	{
		*ptr-- = *ptr2--;
		i--;
	}
}

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*ptr;
	const char	*ptr2;
	int			i;

	ptr = s1;
	ptr2 = s2;
	i = n;
	if (!overlap(ptr, ptr2, i))
	{
		while (i > 0)
		{
			*ptr++ = *ptr2++;
			i--;
		}
	}
	else
	{
		overlap_move(ptr, ptr2, i);
	}
	return (s1);
}
