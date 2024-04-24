/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:38:19 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/09 20:07:23 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	set_first_coords_edge(t_state *state, t_edge *edge, int i, int j)
{
	edge->start_x = state->map[i][j].x + state->x_offset;
	edge->start_y = state->map[i][j].y + state->y_offset;
	edge->start_color = state->map[i][j].color;
}

static void	set_last_coords_edge(t_state *state, t_edge *edge, int i, int j)
{
	if (!state->map[i] || j >= state->line_size)
		return ;
	edge->final_x = state->map[i][j].x + state->x_offset;
	edge->final_y = state->map[i][j].y + state->y_offset;
	edge->final_color = state->map[i][j].color;
}

static void	paint_edges(t_state *state)
{
	int		i;
	int		j;
	t_edge	next_edge;
	t_edge	below_edge;

	i = 0;
	while (state->map[i])
	{
		j = 0;
		while (j < state->line_size)
		{
			set_first_coords_edge(state, &next_edge, i, j);
			set_first_coords_edge(state, &below_edge, i, j);
			set_last_coords_edge(state, &next_edge, i, j + 1);
			set_last_coords_edge(state, &below_edge, i + 1, j);
			if (j + 1 < state->line_size)
				paint_edge(state, &next_edge);
			if (state->map[i + 1])
				paint_edge(state, &below_edge);
			j++;
		}
		i++;
	}
}

static void	paint_points(t_state *state)
{
	int		i;
	int		j;
	int		x_pos;
	int		y_pos;
	t_point	*point;

	i = 0;
	while (state->map[i])
	{
		j = 0;
		while (j < state->line_size)
		{
			point = &state->map[i][j];
			x_pos = point->x + state->x_offset;
			y_pos = point->y + state->y_offset;
			color_pixel(state->mlx->img_data, x_pos, y_pos, point->color);
			j++;
		}
		i++;
	}
}

void	paint_map(t_state *state)
{
	paint_points(state);
	paint_edges(state);
}
