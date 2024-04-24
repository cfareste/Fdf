/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:41:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/20 17:01:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_list(void *cont, t_list **lst, void (*del) (void *))
{
	del(cont);
	ft_lstclear(lst, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	void	*new_content;
	t_list	*first;
	t_list	*this_node;

	if (!lst || !f || !del)
		return (0);
	first = 0;
	while (lst)
	{
		new_content = f(lst->content);
		this_node = ft_lstnew(new_content);
		if (!this_node)
			return (free_list(new_content, &first, del));
		if (!first)
			first = this_node;
		else
			ft_lstadd_back(&first, this_node);
		this_node = this_node->next;
		lst = lst->next;
	}
	return (first);
}
