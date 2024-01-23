/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:51 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:52 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	prepare_collectibles(t_vars *vars, int col,
								int row, int *collectible)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mushrooms[0],
		col * vars->wall_width, row * vars->wall_height);
	vars->collectibles[*collectible] = (t_coord){row, col};
	(*collectible)++;
}

static void	prepare_enemy(t_vars *vars, int col, int row, int *enemy)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_path,
		col * vars->wall_width, row * vars->wall_height);
	vars->enemies[*enemy] = (t_coord){row, col};
	vars->enemy_dir[*enemy] = -1;
	(*enemy)++;
}

static void	put_p_1_e(t_vars *vars, int col, int row, char c)
{
	int	x;
	int	y;

	x = col * vars->wall_width;
	y = row * vars->wall_height;
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_down, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->gate_close, x, y);
}

static void	match_correct_letter(t_vars *vars)
{
	int		collectibles;
	int		enemy;
	int		col;
	int		row;

	row = 0;
	collectibles = 0;
	enemy = 0;
	while (row < vars->map_height)
	{
		col = 0;
		while (col < vars->map_width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
				col * vars->wall_width, row * vars->wall_height);
			put_p_1_e(vars, col, row, vars->map[row][col]);
			if (vars->map[row][col] == 'C')
				prepare_collectibles(vars, col, row, &collectibles);
			else if (vars->map[row][col] == 'N')
				prepare_enemy(vars, col, row, &enemy);
			col++;
		}
		row++;
	}
}

int	prepare_game(t_vars *vars)
{
	vars->collectibles = malloc(sizeof(t_coord) * vars->n_collect);
	if (!vars->collectibles)
	{
		ft_error("Collectibles allocation error\n");
		return (FALSE);
	}
	if (!init_enemies(vars))
		return (FALSE);
	match_correct_letter(vars);
	ft_show_counter(vars);
	return (TRUE);
}
