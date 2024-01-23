/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:39 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:37:40 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_mushroom_images(t_vars *vars)
{
	int	mushroom;

	mushroom = 0;
	while (mushroom < MUSHROOM_IMGS)
	{
		mlx_destroy_image(vars->mlx, vars->mushrooms[mushroom]);
		vars->mushrooms[mushroom] = NULL;
		mushroom++;
	}
}

static void	destroy_players(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->player_down);
	vars->player_down = NULL;
	mlx_destroy_image(vars->mlx, vars->player_up);
	vars->player_up = NULL;
	mlx_destroy_image(vars->mlx, vars->player_left);
	vars->player_left = NULL;
	mlx_destroy_image(vars->mlx, vars->player_right);
	vars->player_right = NULL;
	mlx_destroy_image(vars->mlx, vars->enemy_path);
	vars->enemy_path = NULL;
	mlx_destroy_image(vars->mlx, vars->enemy_left);
	vars->enemy_left = NULL;
	mlx_destroy_image(vars->mlx, vars->enemy_right);
	vars->enemy_right = NULL;
	mlx_destroy_image(vars->mlx, vars->arrest);
	vars->arrest = NULL;
}

void	destroy_images(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->wall);
	vars->wall = NULL;
	mlx_destroy_image(vars->mlx, vars->background);
	vars->background = NULL;
	mlx_destroy_image(vars->mlx, vars->gate_close);
	vars->gate_close = NULL;
	mlx_destroy_image(vars->mlx, vars->gate_open);
	vars->gate_open = NULL;
	mlx_destroy_image(vars->mlx, vars->stats_background);
	vars->stats_background = NULL;
	mlx_destroy_image(vars->mlx, vars->you_won);
	vars->you_won = NULL;
	mlx_destroy_image(vars->mlx, vars->you_lose);
	vars->you_lose = NULL;
	mlx_destroy_image(vars->mlx, vars->gate_close_with_man);
	vars->gate_close_with_man = NULL;
	mlx_destroy_image(vars->mlx, vars->gate_open_with_man);
	vars->gate_open_with_man = NULL;
	destroy_players(vars);
	destroy_mushroom_images(vars);
}

// Singletone
int	ft_close(t_vars *vars)
{
	static int	closed;

	if (!closed)
	{
		closed++;
		free(vars->collectibles);
		vars->collectibles = NULL;
		free(vars->enemies);
		vars->enemies = NULL;
		free(vars->enemy_dir);
		vars->enemy_dir = NULL;
		free_map(vars);
		destroy_images(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	ft_printf("Exited\n");
	if (OS_LINUX == FALSE)
		exit (0);
	return (OK);
}
