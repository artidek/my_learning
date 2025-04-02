/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:42:14 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/22 12:33:12 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	reverse_rotate(p_list **last, p_list **stack, char ch, int single)
{
	p_list	*temp;
	*last = *stack;
	while ((*last)->next->next)
		*last = (*last)->next;
	temp = (*last)->next;
	temp->next = *stack;
	*stack = temp;
	(*last)->next = NULL;
	if (ch == 'a' && single)
		printf("rra\n");
	if (ch == 'b'&& single)
		printf("rrb\n");
}
