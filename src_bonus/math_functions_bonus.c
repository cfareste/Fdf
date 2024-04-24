/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:17:17 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/09 20:08:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

double	module(int x, int y)
{
	double	module;

	module = sqrt((x * x) + (y * y));
	return (module);
}
