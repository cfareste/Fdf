/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:38:15 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/20 14:20:11 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	int		i;
	int		lst_size;
	t_list	*next_node;

	if (!lst || !*lst || !del)
		return ;
	i = 0;
	lst_size = ft_lstsize(*lst);
	while (i++ < lst_size)
	{
		next_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_node;
	}
	*lst = 0;
}
