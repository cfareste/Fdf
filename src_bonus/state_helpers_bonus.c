/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_helpers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:03:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/17 16:01:10 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static t_point	**process_map(t_state *state)
{
	char		*path_extension;
	char		**raw_map;
	t_point		**map;

	path_extension = ft_strrchr(state->map_path, '.');
	if (ft_strncmp(path_extension, EXTENSION, ft_strlen(EXTENSION) + 1))
		handle_error(state, "Wrong map extension (.fdf)\n");
	raw_map = read_raw_map(state);
	if (!raw_map)
		return (NULL);
	if (!raw_map[0] || !is_every_map_line_equal(state, raw_map))
		handle_error(state, "Wrong map format\n");
	map = parse_map(state, raw_map);
	if (!map)
		return (free_string_matrix(raw_map), NULL);
	free_string_matrix(raw_map);
	return (map);
}

static t_img_data	*init_image_data(t_mlx *mlx)
{
	t_img_data	*img_data;

	img_data = malloc(sizeof(t_img_data));
	if (!img_data)
		return (NULL);
	img_data->image = mlx_new_image(mlx->ptr, IMAGE_WIDTH, IMAGE_HEIGHT);
	if (!img_data->image)
		return (free(img_data), NULL);
	img_data->first_pixel = mlx_get_data_addr(img_data->image, &img_data->bpp, \
		&img_data->line_length, &img_data->endian);
	if (!img_data->first_pixel)
	{
		mlx_destroy_image(mlx->ptr, img_data->image);
		return (free(img_data), NULL);
	}
	img_data->bpp /= BITS_IN_BYTE;
	return (img_data);
}

static t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (free(mlx), NULL);
	mlx->window = mlx_new_window(mlx->ptr, WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
	if (!mlx->window)
		return (free(mlx), NULL);
	mlx->img_data = init_image_data(mlx);
	if (!mlx->img_data)
		return (mlx_destroy_window(mlx->ptr, mlx->window), free(mlx), NULL);
	return (mlx);
}

void	free_state(t_state *state)
{
	int	i;

	i = 0;
	while (state->map && i < state->num_lines)
		free(state->map[i++]);
	if (state->map)
		free(state->map);
	i = 0;
	while (state->backup_map && i < state->num_lines)
		free(state->backup_map[i++]);
	if (state->backup_map)
		free(state->backup_map);
	if (state->mlx && state->mlx->img_data)
		mlx_destroy_image(state->mlx->ptr, state->mlx->img_data->image);
	if (state->mlx)
		mlx_destroy_window(state->mlx->ptr, state->mlx->window);
}

int	init_state(char *map, t_state *state)
{
	ft_bzero(state, sizeof(t_state));
	state->map_path = map;
	state->backup_map = process_map(state);
	if (!state->backup_map)
		return (0);
	state->num_lines = 0;
	state->line_size = 0;
	state->map = process_map(state);
	if (!state->map)
		return (0);
	state->mlx = init_mlx();
	if (!state->mlx)
		return (0);
	calculate_z_maxmin_diff(state);
	state->zoom = 1.0;
	state->scale = calculate_scale(state);
	state->x_offset = (IMAGE_WIDTH + MENU_WIDTH) / 2;
	state->y_offset = IMAGE_HEIGHT / 2;
	state->rotation_started = -1;
	state->translate_start_x = -1;
	state->translate_start_y = -1;
	state->z_factor = calculate_z_factor(state);
	isometric_view(state);
	configure_map(state, state->map);
	return (1);
}
