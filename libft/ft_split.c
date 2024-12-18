/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:22:49 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/18 17:59:25 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_length(char const *s, char c)
{
	int len;

	len = 0;
	while(*s)
	{
		if (*s != c && c != '\0')
		{
			len++;
			s++;
			while(*s != c && *s != '\0')
				s++;
		}
		s++;
	}
}


char	**ft_split(char const *s, char c)
{
	int		size;
	char	**splited;

	size = ft_length(s, c) + 1;

	return (NULL);
}

int main()
{
	char * * tab = ft_split("  tripouille  42  ", ' ');
	tab = ft_split("tripouille", 0);
	tab = ft_split("     ", ' ');
	tab = ft_split("chinimala", ' ');
	tab = ft_split("", ' ');
	char * splitme = strdup("Tripouille");
	tab = ft_split(splitme, ' ');
	free(splitme);
	splitme = strdup("Tripouille ");
	tab = ft_split(splitme, ' ');
	free(splitme);
	splitme = strdup(" Tripouille");
	tab = ft_split(splitme, ' ');
	free(splitme);
	splitme = strdup(" Tripouille ");
	tab = ft_split(splitme, ' ');
	free(splitme);
	splitme = strdup("--1-2--3---4----5-----42");
	tab = ft_split(splitme, '-');
	free(splitme);
}
