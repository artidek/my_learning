/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:17:13 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 19:37:26 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_plist **last, t_plist **stack, char ch, int single)
{
	t_plist	*temp;

	if (!*last)
		*last = last_node(*stack);
	temp = *stack;
	(*last)->next = temp;
	*stack = (*stack)->next;
	(*last)->next->next = NULL;
	(*last) = (*last)->next;
	if (ch == 'a' && single)
		printf("ra\n");
	if (ch == 'b' && single)
		printf("rb\n");
}

void	reverse_rotate(t_plist **last, t_plist **stack, char ch, int single)
{
	t_plist	*temp;

	*last = *stack;
	if (!(*stack)->next)
		return ;
	while ((*last)->next->next)
		*last = (*last)->next;
	temp = (*last)->next;
	temp->next = *stack;
	*stack = temp;
	(*last)->next = NULL;
	if (ch == 'a' && single)
		printf("rra\n");
	if (ch == 'b' && single)
		printf("rrb\n");
}

void	swap(char stack, int single, t_plist **lst_stck)
{
	t_plist	*temp;
	t_plist	*next;

	temp = *lst_stck;
	next = (*lst_stck)->next->next;
	*lst_stck = (*lst_stck)->next;
	temp->next = next;
	(*lst_stck)->next = temp;
	if (stack == 'a' && single)
		printf("sa\n");
	if (stack == 'b' && single)
		printf("sb\n");
}

void	push(t_plist **stack_take, t_plist **stack_put, char ch)
{
	t_plist	*temp;

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
