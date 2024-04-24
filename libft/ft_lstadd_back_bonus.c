/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/20 14:18:12 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*this_node;

	if (!lst)
		return ;
	if (!*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	this_node = *lst;
	while (this_node->next)
		this_node = this_node->next;
	this_node->next = new;
}
