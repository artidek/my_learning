/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:35:14 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/24 10:05:53 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_size(p_list *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

static void	find_targets(p_list **stack_a, p_list **stack_b)
{
	p_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		find_target(&temp,*stack_b);
		temp = temp->next;
	}
}

static void	merge_stacks(p_list **stack_a, p_list **stack_b)
{
	p_list *cheap;
	int	size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		rearange_stack(stack_a, stack_size(*stack_a));
		rearange_stack(stack_b, stack_size(*stack_b));
		find_targets(stack_a, stack_b);
		cheap = find_cheap(*stack_a);
		if ((cheap->reverse && cheap->target->reverse) || (!cheap->reverse && !cheap->target->reverse))
			double_rotate_node(cheap, stack_a, stack_b);
		else
		{
			rotate_node(cheap, stack_a, 'a');
			rotate_node(cheap->target, stack_b, 'b');
		}
		push(stack_a, stack_b, 'b');
		size--;
	}
}

void	split_stack(p_list **stack_a, p_list **stack_b)
{
	push(stack_a,stack_b, 'b');
	push(stack_a,stack_b, 'b');
	//push(stack_a,stack_b, 'b');
	//sort_three(stack_a);
	merge_stacks(stack_a, stack_b);
	//sort_three(stack_a);
	push(stack_a,stack_b, 'b');
	final_merge(stack_a, stack_b);
}
