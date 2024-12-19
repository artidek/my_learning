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

//#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	nstr(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c && c != '\0')
		{
			len++;
			while (*s != c && *s != '\0')
				s++;
		}
		if (*s != '\0')
			s++;
	}
	return (len);
}

static void checkItems(char **arr, int size)
{
	char **temp;
	int i;

	temp = arr;
	i = 0;
	while(size > 0)
	{
		if (*temp == NULL && size > 1)
		{
			while(arr[i] != NULL)
			{
				free(arr[i]);
				i++;
			}
			free(arr);
			return;
		}
		temp++;
	}
}
static void ft_strlcpy(char *dst, const char *src, int len)
{
	if (dst == NULL)
		return;
	while (len > 0)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	*dst = '\0';
}

static int insertItme(char const *s, char c, char **arr)
{
	int pos;
	int len;
	const char *start;
	char *itm;

	len = 0;
	pos = 0;
	while (*s == c && c != '\0')
	{
		pos++;
		s++;
	}
	start = s;
	printf("%s\n", start);
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	printf("%d\n", len);
	itm = malloc(sizeof(char) * len + 1);
	if (itm == NULL)
		*arr == NULL;
	ft_strlcpy(itm, start, len + 1);
	*arr = itm;
	return (pos + len);
}
char	**ft_split(char const *s, char c)
{
	int		size;
	char	**splited;
	int		pos;

	size = nstr(s, c);
	if (size == 0)
		splited = malloc(sizeof(char *) * 1);
	if (size > 0)
		splited = malloc(sizeof(char *) * size + 1);
	if (splited == NULL)
		return (NULL);
	pos = 0;
	while (size > 0)
	{
		pos = insertItme(s, c, splited);
		s += pos;
		splited++;
		size--;
	}
	splited[size] = NULL;
	checkItems(splited, size + 1);
	return (NULL);
}

void	freeTab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(void)
{
	char	*splitme;
	char	**tab;

	tab = ft_split("  tripouille  42  ", ' ');
	printf("%s\n", tab[0]);
	freeTab(tab);
	//tab = ft_split("tripouille", 0);
	// freeTab(tab);
	//tab = ft_split("     ", ' ');
	// freeTab(tab);
	//tab = ft_split("chinimala", ' ');
	// freeTab(tab);
	//tab = ft_split("", ' ');
	// freeTab(tab);
	//splitme = strdup("Tripouille");
	//tab = ft_split(splitme, ' ');
	//free(splitme);
	//splitme = strdup("Tripouille ");
	//tab = ft_split(splitme, ' ');
	//free(splitme);
	//splitme = strdup(" Tripouille");
	//tab = ft_split(splitme, ' ');
	//free(splitme);
	//splitme = strdup(" Tripouille ");
	//tab = ft_split(splitme, ' ');
	//free(splitme);
	//splitme = strdup("--1-2--3---4----5-----42");
	//tab = ft_split(splitme, '-');
	//free(splitme);
}
