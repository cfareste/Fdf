/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:26:35 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/13 12:18:07 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	n;
	int	neg;
	int	i;

	n = 0;
	neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	return (n * neg);
}
