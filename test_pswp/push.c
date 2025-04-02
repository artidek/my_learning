/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:56:47 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/22 12:39:25 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	push(p_list **stack_take, p_list **stack_put, char ch)
{
	p_list *temp;

	temp = (*stack_take)->next;
	if (!*stack_put)
	{
		(*stack_take)->next = NULL;
		*stack_put = *stack_take;
	}
	else if (*stack_take)
		add_front(stack_put, *stack_take);
	*stack_take = temp;
	if (ch == 'a')
		printf("pa\n");
	if (ch == 'b')
		printf("pb\n");
}
