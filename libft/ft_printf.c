/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:19:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/17 01:11:47 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_parameter(char const *str, int *pos, va_list args, t_flags *flags)
{
	char	specifier;

	specifier = str[*pos];
	if (specifier == 'c')
		return (print_character(va_arg(args, int), flags));
	else if (specifier == 's')
		return (print_string(va_arg(args, char *), flags));
	else if (specifier == 'p')
		return (print_pointer(va_arg(args, void *), flags));
	else if (specifier == 'd' || specifier == 'i')
		return (print_number(va_arg(args, int), flags));
	else if (specifier == 'u')
		return (print_unsigned_number(va_arg(args, unsigned int), flags));
	else if (specifier == 'x' || specifier == 'X')
		return (print_hex_nbr(va_arg(args, unsigned int), specifier, flags));
	else if (specifier == '%')
		return (print_character('%', flags));
	else
		return (print_raw_char(specifier));
}

int	handle_flag(char const *str, int *pos, va_list args, t_flags *flags)
{
	*pos = *pos + 1;
	reset_flags(flags);
	if (count_flags(str, pos, flags) == -1)
		return (-1);
	return (handle_parameter(str, pos, args, flags));
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		final_length;
	int		bytes_written;
	va_list	args;
	t_flags	flags;

	i = 0;
	final_length = 0;
	reset_flags(&flags);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			bytes_written = handle_flag(str, &i, args, &flags);
		else
			bytes_written = print_raw_char(str[i]);
		if (bytes_written == -1)
			return (va_end(args), -1);
		final_length += bytes_written;
		i++;
	}
	va_end(args);
	return (final_length);
}
