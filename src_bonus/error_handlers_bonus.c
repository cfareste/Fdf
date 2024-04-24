/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:10:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/09 20:09:09 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	custom_error(char *error)
{
	int	error_len;

	error_len = ft_strlen(error);
	write(STDERR_FILENO, "Error: ", ERROR_PREFIX_LEN);
	write(STDERR_FILENO, error, error_len);
}

void	handle_error(t_state *state, char *error)
{
	if (state)
		free_state(state);
	if (error)
		custom_error(error);
	else
		perror("fdf");
	exit (1);
}
