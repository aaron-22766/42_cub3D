/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:14:53 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/23 03:29:45 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_lstnew_safe(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
	{
		free(content);
		return (NULL);
	}
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

static	t_list	*ft_valid(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = ft_lstnew_safe((*f)(lst->content));
	if (head == NULL)
	{
		return (NULL);
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;
	t_list	*cur;

	head = ft_valid(lst, f, del);
	if (head == NULL)
		return (NULL);
	node = head;
	cur = lst->next;
	while (cur)
	{
		node->next = ft_lstnew_safe((*f)(cur->content));
		if (node->next == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		node = node->next;
		cur = cur->next;
	}
	return (head);
}
