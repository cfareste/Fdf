/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_complex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:58:27 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/19 10:22:15 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_string(char *str, t_flags *flags)
{
	int	bytes_written;
	int	spaces_written;

	if (!str)
		return (print_string("(null)", flags));
	process_precision(str, flags);
	if (flags->minus)
	{
		bytes_written = print_precised_string(str, flags->precision);
		if (bytes_written == -1)
			return (-1);
		spaces_written = print_width(flags->width - bytes_written, ' ');
		if (spaces_written == -1)
			return (-1);
	}
	else
	{
		spaces_written = print_width(calculate_width(str, flags), ' ');
		if (spaces_written == -1)
			return (-1);
		bytes_written = print_precised_string(str, flags->precision);
		if (bytes_written == -1)
			return (-1);
	}
	return (spaces_written + bytes_written);
}

int	print_pointer(void *ptr, t_flags *flags)
{
	unsigned long	ptr_value;
	int				num_length;
	char			*num_str;

	if (!ptr)
		return (print_string("0x0", flags));
	ptr_value = (unsigned long) ptr;
	num_length = calculate_total_hex_num_length(ptr_value) + ft_strlen("0x");
	num_str = malloc(num_length + 1);
	if (!num_str)
		return (-1);
	ft_memcpy(num_str, "0x", 2);
	puthex_in_str(num_str, ptr_value, num_length);
	num_length = print_string(num_str, flags);
	free(num_str);
	return (num_length);
}

int static	print_hex_str(char *n_str, t_flags *flags, char sp, unsigned int n)
{
	int	byt_wri;
	int	wdt_wri;

	if (flags->minus)
	{
		if (flags->hashtag && print_hex_prefix(n, sp) == -1)
			return (-1);
		byt_wri = print_precised_number(n_str, flags, n);
		if (byt_wri == -1)
			return (-1);
		wdt_wri = print_width(calc_total_width(n_str, flags, byt_wri), ' ');
		if (wdt_wri == -1)
			return (-1);
		return (byt_wri + wdt_wri + ((n && flags->hashtag) * 2));
	}
	wdt_wri = 0;
	if ((!flags->zero && flags->width)
		|| (flags->zero && flags->precision != -2 && flags->width))
		wdt_wri = print_width(calc_total_width(n_str, flags, 0), ' ');
	if (wdt_wri == -1 || (flags->hashtag && print_hex_prefix(n, sp) == -1))
		return (-1);
	byt_wri = print_precised_number(n_str, flags, n);
	if (byt_wri == -1)
		return (-1);
	return (byt_wri + wdt_wri + ((n && flags->hashtag) * 2));
}

int	print_hex_nbr(unsigned int n, char specifier, t_flags *flags)
{
	char	*num_str;
	int		num_length;

	num_length = calculate_total_hex_num_length(n);
	num_str = malloc(num_length + 1);
	if (!num_str)
		return (-1);
	puthex_in_str(num_str, n, num_length);
	if (specifier == 'X')
		transform_hex_toupper(num_str);
	num_length = print_hex_str(num_str, flags, specifier, n);
	free(num_str);
	return (num_length);
}
