/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_merge_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:35:14 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 20:07:17 by aobshatk         ###   ########.fr       */
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

static void	find_targets(t_plist **stack_a, t_plist **stack_b, t_min_max mn_mx)
{
	t_plist	*temp;

	temp = *stack_a;
	while (temp)
	{
		find_target(&temp, *stack_b, mn_mx);
		temp = temp->next;
	}
}

static void	merge_stacks(t_plist **stack_a, t_plist **stack_b, t_min_max mn_mx)
{
	t_plist	*cheap;
	int		size;

	size = stack_size(*stack_a);
	while (!sorted(*stack_a) && size > 3)
	{
		rearange_stack(stack_a, stack_size(*stack_a));
		rearange_stack(stack_b, stack_size(*stack_b));
		find_targets(stack_a, stack_b, mn_mx);
		cheap = find_cheap(*stack_a);
		if ((cheap->reverse && cheap->target->reverse) || (!cheap->reverse
				&& !cheap->target->reverse))
			double_rotate_node(cheap, 'a', stack_a, stack_b);
		else
		{
			rotate_node(cheap, stack_a, 'a');
			rotate_node(cheap->target, stack_b, 'b');
		}
		push(stack_a, stack_b, 'b');
		mn_mx = min_max(*stack_b, mn_mx);
		size--;
	}
}

void	split_stack(t_plist **stack_a, t_plist **stack_b)
{
	t_min_max	mn_mx;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	if ((*stack_b)->value > (*stack_b)->next->value)
	{
		mn_mx.max = (*stack_b)->value;
		mn_mx.min = (*stack_b)->next->value;
	}
	else
	{
		mn_mx.max = (*stack_b)->next->value;
		mn_mx.min = (*stack_b)->value;
	}
	merge_stacks(stack_a, stack_b, mn_mx);
	if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	final_merge(stack_a, stack_b);
}
