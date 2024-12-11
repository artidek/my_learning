/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:24:11 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/11 21:24:11 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*temdup;
	int		len;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	temdup = dup;
	while (*s)
		*temdup++ = *s++;
	*temdup = '\0';
	return (dup);
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int	size;

	size = 0;
	if (!lst || !del)
		return ;
	size = ft_lstsize(*lst);
	while(size > 0)
	{
		del((*lst)->content);
		free(lst);
		if ((*lst)->next)
			lst = &(*lst)->next;
		size--;
	}
	lst = NULL;
}

void del (void *ptr)
{
	if (!ptr)
		return;
	printf("%s\n", ptr);
	free(ptr);
}

int main()
{
	t_list *test;
	t_list *delptr;
	int size = 0;

	test = ft_lstnew(ft_strdup("string"));
	test->next = ft_lstnew(ft_strdup("string"));
	test->next->next = ft_lstnew(ft_strdup("del str"));
	test->next->next->next = ft_lstnew(ft_strdup("string"));
	test->next->next->next->next = ft_lstnew(ft_strdup("string"));
	delptr = test->next->next;
	ft_lstclear(&delptr, del);
	size = ft_lstsize(test);
	printf("%d\n", size);
	while(size > 0)
	{
		//printf("%s\n", test->content);
		free(test);
		test = test->next;
		size++;
	}
}