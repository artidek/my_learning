/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:13:29 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/08 06:13:29 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5};
	int	*ptr;
	int	i;

	ptr = arr;
	i = *ptr;
	ft_rev_int_tab(&i, 5);
	printf("%d", arr[1]);
	return (0);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int *tab_temp;
	int i;
	int a;

	a = size;

	while (a > 0)
	{
		a--;
		i = *tab + a;
		//printf("%d", i);
		*tab_temp = i;
		*tab_temp = *tab + a;
		*tab_temp ++;


	}


}