/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_global_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:29:07 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/17 04:47:24 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_width(int bytes, char byte_to_print)
{
	int	i;

	i = 0;
	while (i < bytes)
	{
		if (print_raw_char(byte_to_print) == -1)
			return (-1);
		i++;
	}
	return (i);
}
