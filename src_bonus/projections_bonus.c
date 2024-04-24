/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:09:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/11 13:15:21 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	isometric_view(t_state *state)
{
	state->rotations_angles[X_AXIS] = M_PI / 4.0;
	state->rotations_angles[Y_AXIS] = 0;
	state->rotations_angles[Z_AXIS] = M_PI / 4.0;
}

void	parallel_view(t_state *state)
{
	state->rotations_angles[X_AXIS] = M_PI / 2.0;
	state->rotations_angles[Y_AXIS] = 0;
	state->rotations_angles[Z_AXIS] = 0;
}

void	top_view(t_state *state)
{
	state->rotations_angles[X_AXIS] = 0;
	state->rotations_angles[Y_AXIS] = 0;
	state->rotations_angles[Z_AXIS] = 0;
}
