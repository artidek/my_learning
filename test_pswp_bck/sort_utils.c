/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:16:56 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/23 20:41:31 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rearange_stack(p_list **stack, int size)
{
	p_list	*temp;
	int		mid;
	int		min;
	int		i;

	temp = *stack;
	min = temp->value;
	mid = size / 2;
	i = 0;
	while (temp)
	{
		if (i + 1 > mid && mid > 0)
		{
			temp->reverse = 1;
			temp->moves = size - i;
		}
		if (temp->value < min)
			min = temp->value;
		if (i + 1 <= mid || mid == 0)
		{
			temp->moves = i;
			temp->reverse = 0;
		}
		temp = temp->next;
		i++;
	}
	return (min);
}

p_list	*find_cheap(p_list *stack_a)
{
	p_list	*cheap;

	cheap = stack_a;
	while (stack_a->next)
	{
		if (stack_a->cost < cheap->cost)
			cheap = stack_a;
		stack_a = stack_a->next;
	}
	return (cheap);
}

void	rotate_node(p_list *sorted, p_list **stack, char ch)
{
	p_list	*last;
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

void	sort_three(p_list **stack_a)
{
	p_list	*last;

	last = last_node(*stack_a);
	if ((*stack_a)->value < (*stack_a)->next->value && (*stack_a)->value < (*stack_a)->next->next->value)
		reverse_rotate(&last, stack_a, 'a', 1);
	if ((*stack_a)->value < (*stack_a)->next->value && (*stack_a)->value > (*stack_a)->next->next->value)
		reverse_rotate(&last, stack_a, 'a', 1);
	if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > (*stack_a)->next->next->value)
		rotate(&last, stack_a, 'a', 1);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap('a', 1, stack_a);
}

void find_target(p_list **fnd, p_list *stack)
{
	while (stack)
	{
		if ((*fnd)->value > stack->value && (*fnd)->min == INT_MIN)
		{
			(*fnd)->target = stack;
			(*fnd)->min = (*fnd)->value - stack->value;
			(*fnd)->cost = (*fnd)->moves + stack->moves;
		}
		if ((*fnd)->value > stack->value && (*fnd)->min > (*fnd)->value - stack->value)
		{
			(*fnd)->target = stack;
			(*fnd)->min = (*fnd)->value - stack->value;
			(*fnd)->cost = (*fnd)->moves + stack->moves;
		}
		if ((*fnd)->value < stack->value && (*fnd)->min == INT_MIN && stack->value > (*fnd)->max)
		{
			(*fnd)->target = stack;
			(*fnd)->max = stack->value;
			(*fnd)->cost = (*fnd)->moves + stack->moves;
		}
		stack = stack->next;
	}
	(*fnd)->min = INT_MIN;
	(*fnd)->max = INT_MIN;
}
