/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:47:52 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/12 13:48:21 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list) * 1);
	if (new_lst == NULL)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (lst == NULL)
		return (size);
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
