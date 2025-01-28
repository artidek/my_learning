/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:49:03 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/25 11:08:21 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_list	*ft_lstnew(char *cont)
{
	t_list	*new_lst;
	int	len;
	char	*cntnt;
	int	i;

	len = 0;
	cntnt = NULL;
	i = 0;
	new_lst = (t_list *)malloc(sizeof(t_list) * 1);
	if (new_lst == NULL)
		return (NULL);
	while (cont[len])
		len++;
	cntnt = malloc(len + 1);
	if (!cntnt)
		return (NULL);
	while (cont[i])
	{
		cntnt[i] = cont[i];
		i++;
	}
	cntnt[len] = '\0';
	new_lst->content = cntnt;
	new_lst->next = NULL;
	return (new_lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if ((*lst)->content)
		{
			free((*lst)->content);
			(*lst)->content = NULL;
		}
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

int	lststrlen(t_list *next_line)
{
	int		len;
	int		i;
	char	*contnt;
	int	a = 0;

	len = 0;
	i = 0;
	while (next_line)
	{
		contnt = next_line->content;
		while (contnt[i] != '\n' && contnt[i])
		{
			i++;
			len++;
		}
		if (contnt[i] == '\n')
		{
			len++;
			break ;
		}
		a++;
		next_line = next_line->next;
		i = 0;
	}
	return (len);
}

t_list	*check_nl(t_list *next_line)
{
	int		pos;
	char	*cntnt;

	pos = 0;
	if (!next_line)
		return (NULL);
	while (next_line)
	{
		cntnt = next_line->content;
		while(cntnt[pos] != '\n' && cntnt[pos])
			pos++;
		if (cntnt[pos] == '\n')
		{
			pos++;
			return (next_line);
		}
		pos = 0;
		next_line = next_line->next;
	}
	return (NULL);
}
