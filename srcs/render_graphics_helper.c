/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_graphics_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:54 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:55 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_exit(t_vars *vars, int row, int col)
{
	int	x;
	int	y;

	x = col * vars->wall_width;
	y = row * vars->wall_height;
	if (vars->collected == vars->n_collect)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->gate_open, x, y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->gate_close, x, y);
}

void	ft_put_you_lose(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player.col * vars->wall_width;
	y = vars->player.row * vars->wall_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->arrest, x, y);
	x = (vars->map_width * vars->wall_width - vars->you_lose_width) / 2;
	y = (vars->map_height * vars->wall_height - vars->you_lose_height) / 2;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->you_lose, x, y);
}

void	ft_put_you_won(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player.col * vars->wall_width;
	y = vars->player.row * vars->wall_height;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->gate_open_with_man, x, y);
	x = (vars->map_width * vars->wall_width - vars->you_won_width) / 2;
	y = (vars->map_height * vars->wall_height - vars->you_won_height) / 2;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->you_won, x, y);
}

void	ft_show_counter(t_vars *vars)
{
	char	*str;

	mlx_put_image_to_window(vars->mlx, vars->win, vars->stats_background,
		(vars->map_width - 2) * vars->wall_width,
		(vars->map_height - 1) * vars->wall_height + 10);
	str = ft_itoa(vars->moves);
	mlx_string_put(vars->mlx, vars->win,
		(vars->map_width - 2) * vars->wall_width + 5,
		(vars->map_height - 1) * vars->wall_height + 30, 0xFF1493, "moves :");
	mlx_string_put(vars->mlx, vars->win,
		(vars->map_width - 2) * vars->wall_width + 70,
		(vars->map_height - 1) * vars->wall_height + 30, 0xFF1493, str);
	free(str);
}

void	render_enemy(t_vars *vars, int enemy)
{
	int	x;
	int	y;

	if (vars->enemies[enemy].row == vars->player.row
		&& vars->enemies[enemy].col == vars->player.col)
	{
		ft_put_you_lose(vars);
		ft_printf("You lost\n");
	}
	x = vars->enemies[enemy].col * vars->wall_width;
	y = vars->enemies[enemy].row * vars->wall_height;
	if (vars->enemy_dir[enemy] == LEFT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_left, x, y);
	else if (vars->enemy_dir[enemy] == RIGHT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_right, x, y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_path, x, y);
}
