/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:55:15 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 19:38:24 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_plist	*create_node(int value)
{
	t_plist	*new_node;

	new_node = malloc(sizeof(t_plist));
	new_node->value = value;
	new_node->cost = 0;
	new_node->moves = 0;
	new_node->reverse = 0;
	new_node->next = NULL;
	return (new_node);
}

void	append_node(t_plist **list, t_plist *node)
{
	t_plist	*temp;

	temp = *list;
	if (!*list)
	{
		*list = node;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	clear_list(t_plist **lst)
{
	t_plist	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

void	add_front(t_plist **lst, t_plist *new_node)
{
	if (lst == NULL || new_node == NULL)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}

t_plist	*last_node(t_plist *lst)
{
	t_plist	*temp;

	temp = lst;
	while (temp->next)
	{
		if (!temp->next)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}
