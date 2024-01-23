/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:36:49 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:36:50 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Update the player's previous position and
// Update the player's current position
void	render_move(t_vars *vars, int keycode)
{
	int	x;
	int	y;

	x = vars->player_last.col * vars->wall_width;
	y = vars->player_last.row * vars->wall_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x, y);
	ft_put_exit(vars, vars->exit.row, vars->exit.col);
	x = vars->player.col * vars->wall_width;
	y = vars->player.row * vars->wall_height;
	if (vars->player.row == vars->exit.row
		&& vars->player.col == vars->exit.col)
	{
		if (vars->collected == vars->n_collect)
			ft_put_you_won(vars);
		else
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->gate_close_with_man, x, y);
	}
	else
		render_player_image(vars, keycode, x, y);
	ft_show_counter(vars);
}

void	render_player_image(t_vars *vars, int keycode, int x, int y)
{
	if (keycode == KEY_LEFT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_left, x, y);
	else if (keycode == KEY_RIGHT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_right, x, y);
	else if (keycode == KEY_DOWN)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_down, x, y);
	else if (keycode == KEY_UP)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_up, x, y);
}

void	ft_print_usage(char *prog_name)
{
	ft_printf("Usage: %s <path_to_ber_map>\n", prog_name);
}
