/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 04:43:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/17 04:48:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	process_precision(char *str, t_flags *flags)
{
	if (flags->precision == -2)
		flags->precision = ft_strlen(str);
}

int	print_precised_string(char *str, int precision)
{
	int	i;

	i = 0;
	while (str[i] && precision > 0)
	{
		if (print_raw_char(str[i]) == -1)
			return (-1);
		i++;
		precision--;
	}
	return (i);
}

int	calculate_width(char *str, t_flags *flags)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (strlen > flags->precision)
		return (flags->width - flags->precision);
	else
		return (flags->width - strlen);
}
