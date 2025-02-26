/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:51:21 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 20:06:31 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	double_reverse(t_plist **stack_a, t_plist **stack_b, t_plist **lasta,
		t_plist **lastb)
{
	reverse_rotate(lasta, stack_a, 'a', 0);
	reverse_rotate(lastb, stack_b, 'b', 0);
	printf("rrr\n");
}

void	double_rotate(t_plist **stack_a, t_plist **stack_b, t_plist **lasta,
		t_plist **lastb)
{
	rotate(lasta, stack_a, 'a', 0);
	rotate(lastb, stack_b, 'b', 0);
	printf("rr\n");
}

void	reverse_rotate_nodes(int counta, int countb, t_plist **stack_a,
		t_plist **stack_b)
{
	t_plist	*lasta;
	t_plist	*lastb;

	lasta = NULL;
	lastb = NULL;
	while (counta || countb)
	{
		if (counta && countb)
		{
			double_reverse(stack_a, stack_b, &lasta, &lastb);
			counta--;
			countb--;
		}
		else if (counta && !countb)
		{
			reverse_rotate(&lasta, stack_a, 'a', 1);
			counta--;
		}
		else if (!counta && countb)
		{
			reverse_rotate(&lastb, stack_b, 'b', 1);
			countb--;
		}
	}
}

void	rotate_nodes(int counta, int countb, t_plist **stack_a,
		t_plist **stack_b)
{
	t_plist	*lasta;
	t_plist	*lastb;

	lasta = NULL;
	lastb = NULL;
	while (counta || countb)
	{
		if (counta && countb)
		{
			double_rotate(stack_a, stack_b, &lasta, &lastb);
			counta--;
			countb--;
		}
		else if (counta && !countb)
		{
			rotate(&lasta, stack_a, 'a', 1);
			counta--;
		}
		else if (!counta && countb)
		{
			rotate(&lastb, stack_b, 'b', 1);
			countb--;
		}
	}
}

void	double_rotate_node(t_plist *cheap, char cur, t_plist **stack_a,
		t_plist **stack_b)
{
	if (cur == 'a' && !cheap->reverse)
		rotate_nodes(cheap->moves, cheap->target->moves, stack_a, stack_b);
	if (cur == 'a' && cheap->reverse)
		reverse_rotate_nodes(cheap->moves, cheap->target->moves, stack_a,
			stack_b);
	if (cur == 'b' && !cheap->reverse)
		rotate_nodes(cheap->target->moves, cheap->moves, stack_a, stack_b);
	if (cur == 'b' && cheap->reverse)
		reverse_rotate_nodes(cheap->target->moves, cheap->moves, stack_a,
			stack_b);
}
