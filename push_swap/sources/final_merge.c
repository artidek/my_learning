/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:20:14 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 20:07:53 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	stack_size(t_plist *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

static void	find_targets(t_plist **stack_b, t_plist **stack_a, t_min_max mn_mx)
{
	t_plist	*temp;

	temp = *stack_b;
	while (temp)
	{
		find_target_final(&temp, *stack_a, mn_mx);
		temp = temp->next;
	}
}

static void	merge_stacks(t_plist **stack_a, t_plist **stack_b, t_min_max mn_mx)
{
	t_plist	*cheap;

	while (*stack_b)
	{
		rearange_stack(stack_a, stack_size(*stack_a));
		rearange_stack(stack_b, stack_size(*stack_b));
		find_targets(stack_b, stack_a, mn_mx);
		cheap = find_cheap(*stack_b);
		if ((cheap->reverse && cheap->target->reverse) || (!cheap->reverse
				&& !cheap->target->reverse))
			double_rotate_node(cheap, 'b', stack_a, stack_b);
		else
		{
			rotate_node(cheap, stack_b, 'b');
			rotate_node(cheap->target, stack_a, 'a');
		}
		push(stack_b, stack_a, 'a');
		mn_mx = min_max(*stack_a, mn_mx);
	}
}

void	final_merge(t_plist **stack_a, t_plist **stack_b)
{
	t_min_max	mn_mx;

	if (stack_size(*stack_a) == 3)
	{
		mn_mx.min = (*stack_a)->value;
		mn_mx.max = (*stack_a)->next->next->value;
	}
	if (stack_size(*stack_a) > 3)
	{
		mn_mx.min = (*stack_a)->value;
		mn_mx.max = last_node(*stack_a)->value;
	}
	merge_stacks(stack_a, stack_b, mn_mx);
	final_sort(stack_a);
}
