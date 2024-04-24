/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:54:20 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/19 10:21:27 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

// Structs types
typedef struct s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	hashtag;
	int	zero;
	int	width;
	int	precision;
}	t_flags;

// Main function
int		ft_printf(char const *str, ...);

// Print raw
int		print_raw_char(char c);
int		print_raw_string(char *str);

// Print simple
int		print_character(char c, t_flags *flags);
int		print_number(int n, t_flags *flags);
int		print_unsigned_number(unsigned int n, t_flags *flags);

// Simple helpers
char	*ft_uitoa(unsigned int n);

// Print complex
int		print_string(char *str, t_flags *flags);
int		print_pointer(void *ptr, t_flags *flags);
int		print_hex_nbr(unsigned int n, char specifier, t_flags *flags);

// Complex helpers
int		calculate_total_hex_num_length(unsigned long n);
void	puthex_in_str(char *num_str, unsigned long n, int idx);
void	transform_hex_toupper(char *str);

// Global helpers
int		print_width(int bytes, char byte_to_print);

// Numbers helpers
int		print_precised_number(char *num_str, t_flags *flags, unsigned int n);
int		print_hex_prefix(unsigned int n, char specifier);
int		check_for_signs_flags(int n, t_flags *flags);
int		calc_total_width(char *num_str, t_flags *flags, int bytes_written);

// String helpers
void	process_precision(char *str, t_flags *flags);
int		print_precised_string(char *str, int precision);
int		calculate_width(char *str, t_flags *flags);

// Handle flags helpers
int		count_flags(char const *str, int *pos, t_flags *flags);
void	reset_flags(t_flags *flags);

#endif
