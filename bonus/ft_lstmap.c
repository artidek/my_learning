/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:34:43 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/12 17:56:32 by aobshatk         ###   ########.fr       */
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

	if (!lst || (!f && !del))
		return (NULL);
	retlst = ft_lstnew(lst->content);
	size = ft_lstsize(lst);
	temp = retlst;
	while (lst->next != NULL)
	{
		if (del)
		{
			//need to implement delete functionality
			//change func tested and fine;
		}
		temp->content = f(&(lst->content));
		lst = lst->next;
		temp->next = ft_lstnew(lst->content);
		temp = temp->next;
		//printf("%s\n", (char *)temp->content);
	}
	printf("loop finished\n");
	return (retlst);
}

void	*func(void *ptr)
{
	char	*test;

	test = "fuck";
	return (test);
}

void del(void *ptr)
{

}

int	main(void)
{
	t_list	*orig;
	t_list	*mapped;
	t_list	*temp;

	orig = ft_lstnew("entry");
	orig->next = ft_lstnew("second");
	orig->next->next = ft_lstnew("third");
	orig->next->next->next = ft_lstnew("forth");
	mapped = ft_lstmap(orig, func, NULL);
	temp = mapped;
	while (temp)
	{
		temp  = temp->next;
	}
	temp = orig;
	while (temp)
	{

		temp = orig->next;
		free(orig);
		orig = temp;
	}

	temp = mapped;
	while (temp)
	{
		printf("freing..\n");
		temp = mapped->next;
		free(mapped);
		mapped = temp;
	}
}
