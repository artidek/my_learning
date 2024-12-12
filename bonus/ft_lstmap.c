/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:34:43 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/12 16:37:37 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lstsize(t_list *lst)
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*retlst;
	t_list	*temp;
	int		size;
	void *temp_con;

	if (!lst || (!f && !del))
		return (NULL);
	retlst = ft_lstnew(lst->content);
	size = ft_lstsize(lst);
	temp = retlst;
	while (size > 0)
	{
		if (del)
		{
			del(temp->content);
			temp = temp->next;
		}
		temp_con = temp->content;
		printf("%s\n", (char *)temp->content);
		temp->content = f(temp_con);

		temp->next = ft_lstnew(lst->next->content);
		temp = temp->next;
		lst = lst->next;
	}
	return (retlst);
}

static void *func (void *ptr)
{
	void *ret;

	printf("finished success!");
	ret = ptr;

 	while((*(char *)ptr))
	{
		(*(char *)ptr) += ('z' - 'A');
		ptr++;
	}

	return (ret);
}

int	main(void)
{
	t_list *orig;
	t_list *mapped;
	t_list *temp;

	orig = ft_lstnew("entry");
	orig->next = ft_lstnew("second");
	orig->next->next = ft_lstnew("third");
	orig->next->next->next = ft_lstnew("forth");

	mapped = ft_lstmap(orig, func, NULL);
	while(mapped)
	{
		printf("%s\n", (char *)mapped->content);
		mapped = mapped->next;
	}
	temp = orig;
	while(temp)
	{
		free(temp);
		orig = orig->next;
		temp = orig;
	}
	temp = mapped;
	while(temp)
	{
		free(temp);
		mapped = mapped->next;
		temp = mapped;
	}
}
