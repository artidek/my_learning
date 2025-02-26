/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:02:37 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 19:39:20 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_min_max	min_max(t_plist *stack, t_min_max min_max)
{
	min_max.min = INT_MAX;
	min_max.max = INT_MIN;
	while (stack)
	{
		if (stack->value > min_max.max)
			min_max.max = stack->value;
		if (stack->value < min_max.min)
			min_max.min = stack->value;
		stack = stack->next;
	}
	return (min_max);
}

t_plist	*find_min_max(t_plist *stack, int fnd)
{
	while (stack)
	{
		if (stack->value == fnd)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

int	calculate_cost(t_plist *node)
{
	int	cost;

	cost = 0;
	if ((node->reverse && node->target->reverse) || (!node->reverse
			&& !node->target->moves))
	{
		if (node->moves >= node->target->moves)
			cost = (node->moves + node->target->moves) - node->target->moves;
		if (node->moves < node->target->moves)
			cost = (node->target->moves + node->moves) - node->moves;
	}
	else
		cost = node->moves + node->target->moves;
	return (cost);
}

int	sorted(t_plist *stack)
{
	while (stack->next)
	{
		if (!(stack->value < stack->next->value))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	find_target_final(t_plist **fnd, t_plist *stack, t_min_max min_max)
{
	t_plist	*targt;
	int		diff;

	diff = INT_MAX;
	if ((*fnd)->value < min_max.min)
	{
		targt = find_min_max(stack, min_max.min);
		(*fnd)->target = targt;
		return ;
	}
	if ((*fnd)->value > min_max.max)
	{
		targt = find_min_max(stack, min_max.min);
		(*fnd)->target = targt;
		return ;
	}
	while (stack)
	{
		if ((*fnd)->value < stack->value && stack->value - (*fnd)->value < diff)
		{
			(*fnd)->target = stack;
			diff = stack->value - (*fnd)->value;
		}
		stack = stack->next;
	}
}
