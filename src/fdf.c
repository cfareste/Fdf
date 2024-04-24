/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:21:47 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/09 18:11:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc != 2)
		handle_error(NULL, "Invalid number of arguments\n");
	if (!init_state(argv[1], &state))
		handle_error(&state, NULL);
	paint_background(&state);
	paint_map(&state);
	mlx_put_image_to_window(state.mlx->ptr, state.mlx->window, \
		state.mlx->img_data->image, 0, 0);
	mlx_hook(state.mlx->window, KEY_PRESS, KEY_P_MASK, handle_keypress, &state);
	mlx_hook(state.mlx->window, CLOSE_WINDOW, KEY_P_MASK, close_window, &state);
	mlx_loop(state.mlx->ptr);
	free_state(&state);
	exit(1);
}
