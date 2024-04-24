/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:37:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/17 15:53:15 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	close_window(t_state *state)
{
	free_state(state);
	exit(0);
}

int	handle_mousemove(int x, int y, t_state *state)
{
	if (state->is_translating)
		translate_map(state, x, y);
	else
	{
		state->translate_start_x = -1;
		state->translate_start_y = -1;
	}
	if (state->is_rotating)
		rotate_map(state, x, y);
	else
	{
		state->rotation_x = -1;
		state->rotation_y = -1;
		state->rotation_z = -1;
		state->rotation_started = -1;
	}
	update_image(state);
	return (0);
}

int	handle_btnrelse(int mouse_code, int x, int y, t_state *state)
{
	(void) x;
	(void) y;
	if (mouse_code == MOUSE_WHEEL)
		state->is_translating = 0;
	else if (mouse_code == LEFT_BUTTON || mouse_code == RIGHT_BUTTON)
		state->is_rotating = 0;
	update_image(state);
	return (0);
}

int	handle_btnpress(int mouse_code, int x, int y, t_state *state)
{
	if (mouse_code == SCROLL_UP || mouse_code == SCROLL_DOWN)
		aplicate_zoom(state, mouse_code, x, y);
	else if (mouse_code == MOUSE_WHEEL)
		state->is_translating = 1;
	else if (mouse_code == LEFT_BUTTON)
		state->is_rotating = IS_ROTATING_XY;
	else if (mouse_code == RIGHT_BUTTON)
		state->is_rotating = IS_ROTATING_Z;
	if (mouse_code == LEFT_BUTTON || mouse_code == RIGHT_BUTTON)
		state->rotation_started = -1;
	update_image(state);
	return (0);
}

int	handle_keypress(int key_code, t_state *state)
{
	if (key_code == ESCAPE)
		close_window(state);
	else if (key_code == P_KEY)
		parallel_view(state);
	else if (key_code == T_KEY)
		top_view(state);
	else if (key_code == R_KEY)
		reset_map(state);
	else if (key_code == PLUS_KEY && state->z_factor > MIN_Z_FACTOR)
		state->z_factor /= Z_FACTOR_CHANGE;
	else if (key_code == MINUS_KEY && state->z_factor < MAX_Z_FACTOR)
		state->z_factor *= Z_FACTOR_CHANGE;
	else if (key_code == H_KEY)
		state->is_menu_hidden = !state->is_menu_hidden;
	if (key_code == H_KEY && !state->is_menu_hidden)
		state->x_offset = (IMAGE_WIDTH + MENU_WIDTH) / 2;
	else if (key_code == H_KEY && state->is_menu_hidden)
		state->x_offset = IMAGE_WIDTH / 2;
	update_image(state);
	return (0);
}
