/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:21 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:22 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	if (end_game(vars))
		return (OK);
	if (keycode != KEY_UP && keycode != KEY_DOWN && keycode != KEY_RIGHT
		&& keycode != KEY_LEFT)
		return (OK);
	if (!valid_move(vars, keycode))
		return (OK);
	move(vars, keycode);
	vars->moves++;
	ft_printf("number of step done is %d\n", vars->moves);
	render_move(vars, keycode);
	return (OK);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		ft_close(vars);
	return (0);
}
