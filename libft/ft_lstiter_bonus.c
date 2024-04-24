/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:30 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/20 14:20:41 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	t_list	*this_node;

	if (!lst || !f)
		return ;
	this_node = lst;
	while (this_node->next)
	{
		f(this_node->content);
		this_node = this_node->next;
	}
	f(this_node->content);
}
