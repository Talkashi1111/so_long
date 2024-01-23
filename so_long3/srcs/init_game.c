/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:14 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:37:15 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mushrooms_vars(t_vars *vars)
{
	int	mushroom;

	mushroom = 0;
	while (mushroom < MUSHROOM_IMGS)
		vars->mushrooms[mushroom++] = NULL;
}

static void	init_images(t_vars *vars)
{
	vars->background = NULL;
	vars->player_down = NULL;
	vars->player_up = NULL;
	vars->player_left = NULL;
	vars->player_right = NULL;
	vars->gate_close = NULL;
	vars->gate_open = NULL;
	vars->stats_background = NULL;
	vars->you_won = NULL;
	vars->you_lose = NULL;
	vars->gate_close_with_man = NULL;
	vars->gate_open_with_man = NULL;
	vars->enemy_path = NULL;
	vars->enemy_left = NULL;
	vars->enemy_right = NULL;
	vars->arrest = NULL;
}

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->wall = NULL;
	vars->map = NULL;
	vars->collectibles = NULL;
	vars->enemies = NULL;
	vars->collected = 0;
	vars->n_enemies = 0;
	vars->moves = 0;
	vars->frame_count = 0;
	vars->last_measured_ms = 0;
	init_images(vars);
	init_mushrooms_vars(vars);
}

int	error_mlx_and_map(char *map_path, t_vars *vars)
{
	alloc_map(map_path, vars);
	if (!vars->map)
		return (MAP_ERROR);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (MLX_ERROR);
	return (OK);
}

int	init_game(char *map_path, t_vars *vars)
{
	int	ret;

	init_vars(vars);
	ret = error_mlx_and_map(map_path, vars);
	if (ret != OK)
		return (ret);
	if (!load_images(vars))
	{
		free_map(vars);
		destroy_images(vars);
		destroy_mlx_display(vars);
		return (IMAGE_ERROR);
	}
	if (!init_mlx_window(vars))
	{
		free_map(vars);
		destroy_images(vars);
		destroy_mlx_display(vars);
		return (MLX_ERROR);
	}
	return (OK);
}
