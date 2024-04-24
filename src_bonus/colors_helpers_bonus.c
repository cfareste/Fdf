/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_helpers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:33:52 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/09 20:09:16 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	color_pixel(t_img_data *img_data, int x, int y, int color)
{
	int		pixel_position;
	char	*pixel_address;
	int		*full_pixel_address;

	if (x < 0 || x >= IMAGE_WIDTH || y < 0 || y >= IMAGE_HEIGHT)
		return ;
	pixel_position = (y * img_data->line_length) + (x * img_data->bpp);
	pixel_address = img_data->first_pixel + pixel_position;
	full_pixel_address = (int *) pixel_address;
	*full_pixel_address = color;
}

int	create_color_argb(int alpha, int red, int green, int blue)
{
	if (alpha < 0 || alpha > MAX_VALUE_COLOR_COMPONENT)
		alpha = 0;
	if (red < 0 || red > MAX_VALUE_COLOR_COMPONENT)
		red = 0;
	if (green < 0 || green > MAX_VALUE_COLOR_COMPONENT)
		green = 0;
	if (blue < 0 || blue > MAX_VALUE_COLOR_COMPONENT)
		blue = 0;
	return (alpha << ALPHA_BIT | red << RED_BIT | green << GREEN_BIT | blue);
}

int	get_color_component(int color, int component)
{
	return ((color >> component) & MAX_VALUE_COLOR_COMPONENT);
}

int	calculate_pixel_color(t_state *state, t_point *point)
{
	int		alpha;
	int		red;
	int		green;
	int		blue;
	double	fct;

	if (state->biggest_z - state->smallest_z == 0)
		fct = fabs(point->z + abs(state->smallest_z));
	else
		fct = fabs(point->z + abs(state->smallest_z)) / \
			(state->biggest_z - state->smallest_z);
	alpha = calc_new_comp(BOTTOM_COLOR, TOP_COLOR, ALPHA_BIT, fct);
	red = calc_new_comp(BOTTOM_COLOR, TOP_COLOR, RED_BIT, fct);
	green = calc_new_comp(BOTTOM_COLOR, TOP_COLOR, GREEN_BIT, fct);
	blue = calc_new_comp(BOTTOM_COLOR, TOP_COLOR, BLUE_BIT, fct);
	return (create_color_argb(alpha, red, green, blue));
}

int	calculate_edge_color(t_edge *edge)
{
	int		alpha;
	int		red;
	int		green;
	int		blue;
	double	fct;

	fct = calc_edge_color_factor(edge);
	alpha = calc_new_comp(edge->start_color, edge->final_color, ALPHA_BIT, fct);
	red = calc_new_comp(edge->start_color, edge->final_color, RED_BIT, fct);
	green = calc_new_comp(edge->start_color, edge->final_color, GREEN_BIT, fct);
	blue = calc_new_comp(edge->start_color, edge->final_color, BLUE_BIT, fct);
	return (create_color_argb(alpha, red, green, blue));
}
