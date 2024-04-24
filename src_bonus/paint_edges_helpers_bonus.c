/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_edges_helpers_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:28:46 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/11 21:01:20 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

double	calc_edge_color_factor(t_edge *edge)
{
	int		dx;
	int		dy;
	double	factor;

	dx = edge->final_x - edge->start_x;
	dy = edge->final_y - edge->start_y;
	if (abs(dx) > abs(dy))
		factor = (edge->x - edge->start_x) / (edge->final_x - edge->start_x);
	else
		factor = (edge->y - edge->start_y) / (edge->final_y - edge->start_y);
	return (factor);
}

int	calc_new_comp(int color0, int color1, int mask, double factor)
{
	int	comp0;
	int	comp1;
	int	new_comp;

	comp0 = get_color_component(color0, mask);
	comp1 = get_color_component(color1, mask);
	new_comp = comp0 + (comp1 - comp0) * factor;
	return (new_comp);
}

static void	slope_over_one(t_state *state, t_edge *edge, double dx, double dy)
{
	int		i;
	double	error;

	i = 1;
	error = 2 * fabs(dx) - fabs(dy);
	while (i < fabs(dy))
	{
		if (dy > 0)
			edge->y += 1;
		else
			edge->y -= 1;
		if (error < 0)
			error = error + 2 * fabs(dx);
		else
		{
			if (dx > 0)
				edge->x += 1;
			else
				edge->x -= 1;
			error = error + 2 * fabs(dx) - 2 * fabs(dy);
		}
		color_pixel(state->mlx->img_data, edge->x, edge->y, \
			calculate_edge_color(edge));
		i++;
	}
}

static void	slope_under_one(t_state *state, t_edge *edge, double dx, double dy)
{
	int		i;
	double	error;

	i = 1;
	error = 2 * fabs(dy) - fabs(dx);
	while (i < fabs(dx))
	{
		if (dx > 0)
			edge->x += 1;
		else
			edge->x -= 1;
		if (error < 0)
			error = error + 2 * fabs(dy);
		else
		{
			if (dy > 0)
				edge->y += 1;
			else
				edge->y -= 1;
			error = error + 2 * fabs(dy) - 2 * fabs(dx);
		}
		color_pixel(state->mlx->img_data, edge->x, edge->y, \
			calculate_edge_color(edge));
		i++;
	}
}

void	paint_edge(t_state *state, t_edge *edge)
{
	double	dx;
	double	dy;

	edge->x = edge->start_x;
	edge->y = edge->start_y;
	dx = edge->final_x - edge->start_x;
	dy = edge->final_y - edge->start_y;
	if (((edge->final_x < 0 || edge->final_x > IMAGE_WIDTH)
			|| (edge->final_y < 0 || edge->final_y > IMAGE_HEIGHT))
		&& ((edge->start_x < 0 || edge->start_x > IMAGE_WIDTH)
			|| (edge->start_y < 0 || edge->start_y > IMAGE_HEIGHT)))
		return ;
	if (fabs(dx) < fabs(dy))
		slope_over_one(state, edge, dx, dy);
	else
		slope_under_one(state, edge, dx, dy);
}
