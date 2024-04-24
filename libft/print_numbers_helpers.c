/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:09:47 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/19 10:21:52 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_total_width(char *num_str, t_flags *flags, int bytes_written)
{
	int	strlen;
	int	has_sign;
	int	is_neg;
	int	is_zero;
	int	has_hex_prefix;

	is_neg = num_str[0] == '-';
	has_sign = is_neg || flags->space || flags->plus;
	strlen = ft_strlen(num_str + is_neg);
	is_zero = !ft_strncmp(num_str, "0", strlen);
	has_hex_prefix = ((!is_zero && flags->hashtag) * 2);
	if (!bytes_written)
	{
		if (strlen - is_neg >= flags->precision)
			bytes_written = strlen + has_sign;
		else
			bytes_written = flags->precision + has_sign;
	}
	if (!flags->precision && is_zero)
		return (flags->width - has_sign);
	return (flags->width - bytes_written - has_hex_prefix);
}

int	static	check_padding_difference(char *num_str, t_flags *flags)
{
	int	padding;
	int	has_sign;
	int	is_zero;
	int	has_hex_prefix;

	padding = 0;
	is_zero = !ft_strncmp(num_str, "0", ft_strlen(num_str));
	has_hex_prefix = ((!is_zero && flags->hashtag) * 2);
	has_sign = num_str[0] == '-' || flags->space || flags->plus;
	if (flags->precision != -2)
		padding = flags->precision;
	else if (!flags->minus && flags->zero)
		padding = flags->width - has_sign - has_hex_prefix;
	return (padding);
}

int	print_precised_number(char *num_str, t_flags *flags, unsigned int n)
{
	int	i;
	int	precision;
	int	padding;
	int	num_length;
	int	has_sign;

	i = 0;
	has_sign = (flags->plus || flags->space || num_str[0] == '-');
	if (!flags->precision && !n)
		return (has_sign);
	if (num_str[i] == '-' && print_raw_char(num_str[i++]) == -1)
		return (-1);
	num_length = ft_strlen(&num_str[i]);
	padding = check_padding_difference(num_str, flags);
	if (num_length >= padding)
		precision = 0;
	else
		precision = padding - num_length;
	if (print_width(precision, '0') == -1)
		return (-1);
	if (print_raw_string(&num_str[i]) == -1)
		return (-1);
	return (precision + num_length + has_sign);
}

int	print_hex_prefix(unsigned int n, char specifier)
{
	if (!n)
		return (0);
	if (specifier == 'X')
		return (print_raw_string("0X"));
	else
		return (print_raw_string("0x"));
}

int	check_for_signs_flags(int n, t_flags *flags)
{
	if (flags->plus && n >= 0 && print_raw_char('+') == -1)
		return (-1);
	if (!flags->plus && flags->space && n >= 0 && print_raw_char(' ') == -1)
		return (-1);
	return (0);
}
