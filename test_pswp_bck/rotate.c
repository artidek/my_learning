/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:39:18 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/22 12:41:41 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	rotate(p_list **last, p_list **stack, char ch, int single)
{
	p_list	*temp;

	if (!*last)
		*last = last_node(*stack);
	temp = *stack;
	(*last)->next = temp;
	*stack = (*stack)->next;
	(*last)->next->next = NULL;
	(*last) = (*last)->next;
	if (ch == 'a' && single)
		printf("ra\n");
	if (ch == 'b'&& single)
		printf("rb\n");
}
