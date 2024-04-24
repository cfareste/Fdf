/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map_helpers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:10:19 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/11 13:28:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	calculate_scale(t_state *state)
{
	int		i;
	double	diagonal;

	i = 1;
	diagonal = round(module(state->line_size, state->num_lines));
	while (i * diagonal < WINDOW_WIDTH && i * diagonal < WINDOW_HEIGHT)
		i++;
	return (i);
}

int	calculate_z_maxmin_diff(t_state *state)
{
	int		i;
	int		j;
	t_point	*point;

	i = 0;
	while (state->map[i])
	{
		j = 0;
		while (j < state->line_size)
		{
			point = &state->map[i][j];
			if (point->z > state->biggest_z)
				state->biggest_z = point->z;
			if (point->z < state->smallest_z)
				state->smallest_z = point->z;
			j++;
		}
		i++;
	}
	return (state->biggest_z - state->smallest_z);
}

double	calculate_z_factor(t_state *state)
{
	double	z_maxmin_diff;
	double	factor;

	factor = 1;
	z_maxmin_diff = abs(state->biggest_z - state->smallest_z);
	if (z_maxmin_diff >= MAX_Z_DIFF)
		factor = state->scale * (z_maxmin_diff / (MAX_Z_DIFF * 2));
	return (factor);
}

void	add_config_to_map(t_state *state, t_point **map,
	void (*conf) (t_state *state, t_point **map, int x_pos, int y_pos))
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < state->line_size)
		{
			conf(state, map, i, j);
			j++;
		}
		i++;
	}
}

void	configure_map(t_state *state, t_point **map)
{
	add_config_to_map(state, map, calc_color_point);
	add_config_to_map(state, map, center_point);
	add_config_to_map(state, map, space_point);
	add_config_to_map(state, map, rotate_point);
}
