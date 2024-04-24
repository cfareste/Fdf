/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:37:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/15 16:22:14 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_state *state)
{
	free_state(state);
	exit(0);
}

int	handle_keypress(int key_code, t_state *state)
{
	if (key_code == ESCAPE)
		close_window(state);
	return (0);
}
