/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_raw_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:22:20 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/17 01:23:03 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_raw_char(char c)
{
	return (write(1, &c, 1));
}

int	print_raw_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (print_raw_string("(null)"));
	while (str[i])
	{
		if (print_raw_char(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
