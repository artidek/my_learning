/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:23:31 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/24 08:50:59 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static p_list	*find_min(p_list *stack_a)
{
	p_list	*min;

	min = stack_a;
	while(stack_a)
	{
		if (stack_a->value < min->value)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

void	final_sort(p_list **stack_a)
{
	int	size;
	p_list	*temp;
	p_list	*min;

	temp = *stack_a;
	size = 0;
	while(temp)
	{
		size++;
		temp = temp->next;
	}
	rearange_stack(stack_a, size);
	min = find_min(*stack_a);
	rotate_node(min, stack_a, 'a');
}
