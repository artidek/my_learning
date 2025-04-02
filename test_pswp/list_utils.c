/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:55:15 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/23 17:53:51 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

p_list	*create_node(int value)
{
	p_list *new_node;

	new_node = malloc(sizeof(p_list));
	new_node->value = value;
	new_node->cost = 0;
	new_node->min = INT_MIN;
	new_node->max = INT_MIN;
	new_node->moves = 0;
	new_node->reverse = 0;
	new_node->next = NULL;
	return (new_node);
}

void	append_node(p_list **list, p_list *node)
{
	p_list	*temp;

	temp = *list;
	if (!*list)
	{
		*list = node;
		return;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	clear_list(p_list **lst)
{
	p_list	*temp;

	if (!*lst)
		return;
	while (*lst)
	{
		temp = (*lst)->next;
		//temp->target = NULL;
		free(*lst);
		*lst = temp;
	}
	
}

void	add_front(p_list **lst, p_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

p_list	*last_node(p_list *lst)
{
	p_list	*temp;

	temp = lst;
	while (temp->next)
	{
		if (!temp->next)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}
