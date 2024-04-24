/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_painter_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:52:56 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/17 15:31:34 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	paint_menu_layout(t_state *state)
{
	int	i;
	int	j;

	i = 0;
	while (i < MENU_WIDTH)
	{
		j = 0;
		while (j < MENU_HEIGHT)
		{
			color_pixel(state->mlx->img_data, i, j, MENU_COLOR);
			j++;
		}
		i++;
	}
}

static void	menu_str(t_state *state, char *str, int x_pos, int y_pos)
{
	mlx_string_put(state->mlx->ptr, state->mlx->window, x_pos, y_pos, \
		STR_COLOR, str);
}

void	write_menu_hud(t_state *state)
{
	int	x_pos;
	int	y_pos;
	int	y_off;

	x_pos = TAB_SIZE;
	y_pos = NEW_LINE;
	y_off = (MENU_HEIGHT / 2) - (NEW_LINE * 13 / 2);
	menu_str(state, "Controls menu (hide/show: H):", x_pos, y_pos + y_off);
	menu_str(state, "----------------------------", x_pos, y_pos * 1.5 + y_off);
	menu_str(state, "Scroll: Zoom in / Zoom out", x_pos, y_pos * 3 + y_off);
	menu_str(state, "Left click: Rotate X / Y axis", x_pos, y_pos * 4 + y_off);
	menu_str(state, "Right click: Rotate Z axis", x_pos, y_pos * 5 + y_off);
	menu_str(state, "Middle click: Translate map", x_pos, y_pos * 6 + y_off);
	menu_str(state, "'+' & '-': Change map heights", x_pos, y_pos * 7 + y_off);
	menu_str(state, "P: Parallel view", x_pos, y_pos * 8 + y_off);
	menu_str(state, "T: Top view", x_pos, y_pos * 9 + y_off);
	menu_str(state, "R: Reset map", x_pos, y_pos * 10 + y_off);
	menu_str(state, "ESCAPE: Close program", x_pos, y_pos * 11 + y_off);
}
