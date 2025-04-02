/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:46:32 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/22 12:30:46 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	swap(char stack, int single, p_list **lst_stck)
{
	p_list *temp;
	p_list	*next;

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
