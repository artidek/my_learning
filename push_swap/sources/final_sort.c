/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:23:31 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 19:32:24 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_plist	*find_min(t_plist *stack_a)
{
	t_plist	*min;

	min = stack_a;
	while (stack_a)
	{
		if (stack_a->value < min->value)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

void	final_sort(t_plist **stack_a)
{
	int		size;
	t_plist	*temp;
	t_plist	*min;

	temp = *stack_a;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	rearange_stack(stack_a, size);
	min = find_min(*stack_a);
	rotate_node(min, stack_a, 'a');
}
