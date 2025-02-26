/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:16:56 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 20:08:46 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rearange_stack(t_plist **stack, int size)
{
	t_plist	*temp;
	int		mid;
	int		i;

	temp = *stack;
	mid = size / 2;
	i = 0;
	while (temp)
	{
		if (i + 1 > mid && mid > 0)
		{
			temp->reverse = 1;
			temp->moves = size - i;
		}
		if (i + 1 <= mid || mid == 0)
		{
			temp->moves = i;
			temp->reverse = 0;
		}
		temp = temp->next;
		i++;
	}
}

t_plist	*find_cheap(t_plist *stack)
{
	t_plist	*cheap;

	stack->cost = calculate_cost(stack);
	cheap = stack;
	while (stack)
	{
		stack->cost = calculate_cost(stack);
		if (stack->cost < cheap->cost)
			cheap = stack;
		stack = stack->next;
	}
	return (cheap);
}

void	rotate_node(t_plist *sorted, t_plist **stack, char ch)
{
	t_plist	*last;
	int		count;

	last = last_node(*stack);
	count = sorted->moves;
	if (sorted->reverse)
	{
		while (count > 0)
		{
			reverse_rotate(&last, stack, ch, 1);
			count--;
		}
		return ;
	}
	while (count > 0)
	{
		rotate(&last, stack, ch, 1);
		count--;
	}
}

void	sort_three(t_plist **stack_a)
{
	t_plist	*last;

	last = last_node(*stack_a);
	if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value)
		reverse_rotate(&last, stack_a, 'a', 1);
	if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		reverse_rotate(&last, stack_a, 'a', 1);
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		rotate(&last, stack_a, 'a', 1);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap('a', 1, stack_a);
}

void	find_target(t_plist **fnd, t_plist *stack, t_min_max min_max)
{
	t_plist	*targt;
	int		diff;

	diff = INT_MAX;
	if ((*fnd)->value < min_max.min)
	{
		targt = find_min_max(stack, min_max.max);
		(*fnd)->target = targt;
		return ;
	}
	if ((*fnd)->value > min_max.max)
	{
		targt = find_min_max(stack, min_max.max);
		(*fnd)->target = targt;
		return ;
	}
	while (stack)
	{
		if ((*fnd)->value > stack->value && (*fnd)->value - stack->value < diff)
		{
			(*fnd)->target = stack;
			diff = (*fnd)->value - stack->value;
		}
		stack = stack->next;
	}
}
