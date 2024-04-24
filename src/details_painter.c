/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_painter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:52:56 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/17 14:27:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	paint_background(t_state *state)
{
	int	i;
	int	j;

	i = 0;
	while (i < IMAGE_WIDTH)
	{
		j = 0;
		while (j < IMAGE_HEIGHT)
		{
			color_pixel(state->mlx->img_data, i, j, BACKGROUND_COLOR);
			j++;
		}
		i++;
	}
}
