/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:23:52 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/09 13:38:15 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**increase_map_array_size(t_state *state, char **map)
{
	int		i;
	char	**new_map;

	new_map = ft_calloc(state->num_lines + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	return (free(map), new_map);
}

char	**read_raw_map(t_state *state)
{
	int		map_fd;
	char	*line;
	char	**raw_map;

	map_fd = open(state->map_path, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	raw_map = ft_calloc(state->num_lines + 1, sizeof(char *));
	if (!raw_map)
		return (close(map_fd), NULL);
	line = get_next_line(map_fd);
	while (line)
	{
		state->num_lines++;
		raw_map = increase_map_array_size(state, raw_map);
		if (!raw_map)
			return (free(line), close(map_fd), NULL);
		raw_map[state->num_lines - 1] = line;
		line = get_next_line(map_fd);
	}
	close(map_fd);
	return (raw_map);
}

static void	init_point(t_point *point, int x_pos, int y_pos, char **num)
{
	point->x = x_pos;
	point->y = y_pos;
	point->z = ft_atoi(num[Z_POS_IDX]);
	if (num[COLOR_IDX])
		point->color = parse_color(num[COLOR_IDX] + 2);
	else
		point->color = -1;
}

static t_point	*parse_line(char **raw_map, int line_index)
{
	int			i;
	int			line_length;
	char		**splitted_line;
	char		**splitted_num;
	t_point		*parsed_line;

	splitted_line = ft_split(raw_map[line_index], ' ');
	if (!splitted_line)
		return (NULL);
	line_length = calculate_string_array_length(splitted_line);
	parsed_line = ft_calloc(line_length, sizeof(t_point));
	if (!parsed_line)
		return (free_string_matrix(splitted_line), NULL);
	i = 0;
	while (splitted_line[i] && splitted_line[i][0] != '\n')
	{
		splitted_num = ft_split(splitted_line[i], ',');
		if (!splitted_num)
			return (free_string_matrix(splitted_line), free(parsed_line), NULL);
		init_point(&parsed_line[i], i, line_index, splitted_num);
		free_string_matrix(splitted_num);
		i++;
	}
	return (free_string_matrix(splitted_line), parsed_line);
}

t_point	**parse_map(t_state *state, char **raw_map)
{
	int		i;
	t_point	**map;

	map = ft_calloc(state->num_lines + 1, sizeof(t_point *));
	if (!map)
		return (NULL);
	i = 0;
	while (raw_map[i])
	{
		map[i] = parse_line(raw_map, i);
		if (!map[i])
			return (free_point_map(map), NULL);
		i++;
	}
	return (map);
}
