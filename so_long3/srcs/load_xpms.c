/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:30 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:31 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_mushroom_images(t_vars *vars)
{
	int	width;
	int	height;

	vars->mushrooms[0] = mlx_xpm_file_to_image(vars->mlx, MUSHROOM_0,
			&width, &height);
	vars->mushrooms[1] = mlx_xpm_file_to_image(vars->mlx, MUSHROOM_1,
			&width, &height);
	vars->mushrooms[2] = mlx_xpm_file_to_image(vars->mlx, MUSHROOM_2,
			&width, &height);
	vars->mushrooms[3] = mlx_xpm_file_to_image(vars->mlx, MUSHROOM_3,
			&width, &height);
	if (!vars->mushrooms[0]
		||!vars->mushrooms[1]
		||!vars->mushrooms[2]
		||!vars->mushrooms[3])
		return (FALSE);
	return (TRUE);
}

static int	verify_xpm(t_vars *vars)
{
	if (!vars->wall
		||!vars->background
		||!vars->gate_close
		||!vars->gate_open
		||!vars->stats_background
		||!vars->you_won
		||!vars->you_lose
		||!vars->gate_close_with_man
		||!vars->gate_open_with_man
		||!vars->player_down
		||!vars->player_up
		||!vars->player_left
		||!vars->player_right
		||!vars->enemy_path
		||!vars->enemy_left
		||!vars->enemy_right
		||!vars->arrest)
	{
		ft_error("Load image error\n");
		return (FALSE);
	}
	if (!load_mushroom_images(vars))
		return (FALSE);
	return (TRUE);
}

static void	load_players_images(t_vars *vars)
{
	int		width;
	int		height;

	vars->player_down = mlx_xpm_file_to_image(vars->mlx, PLAYER_DOWN,
			&width, &height);
	vars->player_up = mlx_xpm_file_to_image(vars->mlx, PLAYER_UP,
			&width, &height);
	vars->player_left = mlx_xpm_file_to_image(vars->mlx, PLAYER_LEFT,
			&width, &height);
	vars->player_right = mlx_xpm_file_to_image(vars->mlx, PLAYER_RIGHT,
			&width, &height);
	vars->enemy_path = mlx_xpm_file_to_image(vars->mlx, ENEMY_PATH,
			&width, &height);
	vars->enemy_left = mlx_xpm_file_to_image(vars->mlx, ENEMY_LEFT,
			&width, &height);
	vars->enemy_right = mlx_xpm_file_to_image(vars->mlx, ENEMY_RIGHT,
			&width, &height);
	vars->arrest = mlx_xpm_file_to_image(vars->mlx, ARREST, &width, &height);
}

static void	load_gate(t_vars *vars)
{
	int	height;
	int	width;

	vars->gate_close = mlx_xpm_file_to_image(vars->mlx, GATE_CLOSE,
			&width, &height);
	vars->gate_open = mlx_xpm_file_to_image(vars->mlx, GATE_OPEN,
			&width, &height);
	vars->gate_close_with_man = mlx_xpm_file_to_image(vars->mlx,
			GATE_CLOSE_PLAYER, &width, &height);
	vars->gate_open_with_man = mlx_xpm_file_to_image(vars->mlx,
			GATE_OPEN_PLAYER, &width, &height);
}

int	load_images(t_vars *vars)
{
	int		width;
	int		height;

	vars->wall = mlx_xpm_file_to_image(vars->mlx, WALL_PATH, &vars->wall_width,
			&vars->wall_height);
	vars->background = mlx_xpm_file_to_image(vars->mlx, BACKGROUND_PATH,
			&width, &height);
	vars->stats_background = mlx_xpm_file_to_image(vars->mlx, COUNTER_PATH,
			&width, &height);
	vars->you_won = mlx_xpm_file_to_image(vars->mlx, YOU_WON,
			&vars->you_won_width, &vars->you_won_height);
	vars->you_lose = mlx_xpm_file_to_image(vars->mlx, YOU_LOSE,
			&vars->you_lose_width, &vars->you_lose_height);
	load_gate(vars);
	load_players_images(vars);
	if (!verify_xpm(vars))
	{
		ft_error("Load image error\n");
		return (FALSE);
	}
	return (TRUE);
}
