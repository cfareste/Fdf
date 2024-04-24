/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:32:46 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/18 19:27:44 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	calculate_num_of_digits(int num)
{
	int	digits;

	digits = 0;
	if (num < 0)
		digits++;
	while (num / 10 != 0)
	{
		digits++;
		num /= 10;
	}
	return (digits + 1);
}

void static	putnbr(char *num, long n, int index)
{
	if (n < 0)
		n *= -1;
	if (n / 10 == 0)
		num[index] = n + '0';
	else
	{
		putnbr(num, n / 10, index - 1);
		num[index] = (n % 10) + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*num;
	int		num_of_digits;

	num_of_digits = calculate_num_of_digits(n);
	num = malloc(num_of_digits + 1 * sizeof(char));
	if (!num)
		return (0);
	num[num_of_digits] = '\0';
	if (n < 0)
		num[0] = '-';
	if (n == 0)
		num[0] = '0';
	else
		putnbr(num, n, num_of_digits - 1);
	return (num);
}
