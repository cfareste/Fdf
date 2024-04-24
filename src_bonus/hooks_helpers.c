/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:32:25 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/17 15:39:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	update_image(t_state *state)
{
	restore_map(state);
	configure_map(state, state->map);
	paint_background(state);
	paint_map(state);
	if (!state->is_menu_hidden)
		paint_menu_layout(state);
	mlx_put_image_to_window(state->mlx->ptr, state->mlx->window, \
		state->mlx->img_data->image, 0, 0);
	if (!state->is_menu_hidden)
		write_menu_hud(state);
}

void	reset_map(t_state *state)
{
	if (!state->is_menu_hidden)
		state->x_offset = (IMAGE_WIDTH + MENU_WIDTH) / 2;
	else
		state->x_offset = IMAGE_WIDTH / 2;
	state->y_offset = IMAGE_HEIGHT / 2;
	state->zoom = 1.0;
	state->z_factor = calculate_z_factor(state);
	isometric_view(state);
}

void	aplicate_zoom(t_state *state, int mouse_code, int mouse_x, int mouse_y)
{
	double	x_pos;
	double	y_pos;

	if ((mouse_code == SCROLL_DOWN && (state->zoom / ZOOM_FACTOR < MIN_ZOOM))
		|| (mouse_code == SCROLL_UP && (state->zoom / ZOOM_FACTOR > MAX_ZOOM)))
		return ;
	x_pos = (mouse_x - state->x_offset);
	y_pos = (mouse_y - state->y_offset);
	if (mouse_code == SCROLL_UP)
	{
		state->x_offset -= x_pos * (ZOOM_FACTOR - 1);
		state->y_offset -= y_pos * (ZOOM_FACTOR - 1);
		state->zoom *= ZOOM_FACTOR;
	}
	else
	{
		state->x_offset -= x_pos * (1 / ZOOM_FACTOR - 1);
		state->y_offset -= y_pos * (1 / ZOOM_FACTOR - 1);
		state->zoom /= ZOOM_FACTOR;
	}
}

void	translate_map(t_state *state, int mouse_x, int mouse_y)
{
	if (state->translate_start_x == -1)
		state->translate_start_x = mouse_x;
	if (state->translate_start_y == -1)
		state->translate_start_y = mouse_y;
	state->x_offset += mouse_x - state->translate_start_x;
	state->y_offset += mouse_y - state->translate_start_y;
	state->translate_start_x = mouse_x;
	state->translate_start_y = mouse_y;
}

void	rotate_map(t_state *state, int mouse_x, int mouse_y)
{
	if (state->is_rotating == IS_ROTATING_XY)
	{
		if (state->rotation_started == -1)
		{
			state->rotation_x = mouse_x;
			state->rotation_y = mouse_y;
			state->rotation_started = 1;
		}
		state->rotations_angles[X_AXIS] -= (mouse_y - state->rotation_y) / SENS;
		state->rotations_angles[Y_AXIS] += (mouse_x - state->rotation_x) / SENS;
		state->rotation_x = mouse_x;
		state->rotation_y = mouse_y;
	}
	else
	{
		if (state->rotation_started == -1)
		{
			state->rotation_z = mouse_x;
			state->rotation_started = 1;
		}
		state->rotations_angles[Z_AXIS] -= (mouse_x - state->rotation_z) / SENS;
		state->rotation_z = mouse_x;
	}
}
