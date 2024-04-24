/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:09:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/04 16:41:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_view(t_state *state)
{
	state->rotations_angles[X_AXIS] = M_PI / 4.0;
	state->rotations_angles[Y_AXIS] = 0;
	state->rotations_angles[Z_AXIS] = M_PI / 4.0;
}
