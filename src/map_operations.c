/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:33:17 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/11 13:30:16 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	space_point(t_state *state, t_point **map, int x_pos, int y_pos)
{
	t_point	*point;

	point = &map[x_pos][y_pos];
	point->x *= state->scale;
	point->y *= state->scale;
	point->z *= state->scale / state->z_factor;
}

void	center_point(t_state *state, t_point **map, int x_pos, int y_pos)
{
	t_point	*point;

	point = &map[x_pos][y_pos];
	point->x -= (state->line_size / 2);
	point->y -= (state->num_lines / 2);
}

void	rotate_point(t_state *state, t_point **map, int x_pos, int y_pos)
{
	t_point	*point;

	point = &map[x_pos][y_pos];
	rotate_z_axis(point, state->rotations_angles[Z_AXIS]);
	rotate_x_axis(point, state->rotations_angles[X_AXIS]);
	rotate_y_axis(point, state->rotations_angles[Y_AXIS]);
}

void	calc_color_point(t_state *state, t_point **map, int x_pos, int y_pos)
{
	t_point	*point;

	point = &map[x_pos][y_pos];
	if (point->color == -1)
		point->color = calculate_pixel_color(state, point);
}

void	restore_map(t_state *state)
{
	int		i;
	int		j;
	t_point	*point;
	t_point	*backup_point;

	i = 0;
	while (state->backup_map[i])
	{
		j = 0;
		while (j < state->line_size)
		{
			point = &state->map[i][j];
			backup_point = &state->backup_map[i][j];
			point->x = backup_point->x;
			point->y = backup_point->y;
			point->z = backup_point->z;
			point->color = backup_point->color;
			j++;
		}
		i++;
	}
}
