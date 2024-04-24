/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_helpers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:01:32 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/09 20:08:50 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	is_every_map_line_equal(t_state *state, char **raw_map)
{
	int		i;
	int		line_size;
	char	**splitted_line;

	i = 0;
	splitted_line = ft_split(raw_map[i++], ' ');
	if (!splitted_line)
		return (0);
	state->line_size = calculate_string_array_length(splitted_line);
	free_string_matrix(splitted_line);
	while (raw_map[i])
	{
		splitted_line = ft_split(raw_map[i], ' ');
		if (!splitted_line)
			handle_error(state, NULL);
		line_size = calculate_string_array_length(splitted_line);
		free_string_matrix(splitted_line);
		if (line_size != state->line_size)
			return (0);
		i++;
	}
	return (1);
}

int	calculate_string_array_length(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i] && array[i][0] != '\n')
		i++;
	return (i);
}

void	free_string_matrix(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	if (map)
		free(map);
}

void	free_point_map(t_point **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	if (map)
		free(map);
}

int	parse_color(char *num)
{
	int		i;
	int		j;
	int		parsed_num;
	char	color_letter;
	char	*base;

	i = 0;
	parsed_num = 0;
	base = "0123456789abcdef";
	while (num[i])
	{
		j = 0;
		color_letter = ft_tolower(num[i]);
		while (base[j] && color_letter != base[j])
			j++;
		if (j >= 16)
			break ;
		parsed_num = (parsed_num * COLOR_BASE_LENGTH) + j;
		i++;
	}
	return (parsed_num);
}
