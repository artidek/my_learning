/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_duplicates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:02:27 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 19:37:48 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_duplicates(t_plist *stack)
{
	t_plist	*check;

	check = stack->next;
	while (stack->next)
	{
		while (check)
		{
			if (check->value == stack->value)
			{
				ft_printf("Error duplicate\n");
				return (1);
			}
			check = check->next;
		}
		stack = stack->next;
		check = stack->next;
	}
	return (0);
}
