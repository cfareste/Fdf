/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:10:13 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/20 14:16:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*this_node;
	int		count;

	count = 0;
	this_node = lst;
	if (!this_node)
		return (0);
	while (this_node->next)
	{
		count++;
		this_node = this_node->next;
	}
	return (count + 1);
}
