/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:06 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:07 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_enemy_next_move(int dir, int *row, int *col)
{
	if (dir == UP)
		(*row)--;
	else if (dir == DOWN)
		(*row)++;
	else if (dir == RIGHT)
		(*col)++;
	else if (dir == LEFT)
		(*col)--;
}

/**
 * Checks if the enemy can make a valid move to the specified position.
 * 
 * @param vars The game variables.
 * @param next_row The next row position of the enemy.
 * @param next_col The next column position of the enemy.
 * @return TRUE if the move is valid, FALSE otherwise.
 */
static int	enemy_valid_move(t_vars *vars, int next_row, int next_col)
{
	if (next_row < 0 || next_row >= vars->map_height
		|| next_col < 0 || next_col >= vars->map_width
		|| vars->map[next_row][next_col] == '1'
		|| vars->map[next_row][next_col] == 'C'
		|| vars->map[next_row][next_col] == 'E'
		|| vars->map[next_row][next_col] == 'N')
	{
		return (FALSE);
	}
	return (TRUE);
}
// Update the enemy's previous position and Update the enemy's current position

static void	update_enemy_position(t_vars *vars, int enemy,
		int next_row, int next_col)
{
	int	x;
	int	y;

	x = vars->enemies[enemy].col * vars->wall_width;
	y = vars->enemies[enemy].row * vars->wall_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x, y);
	vars->map[vars->enemies[enemy].row][vars->enemies[enemy].col] = '0';
	vars->enemies[enemy].row = next_row;
	vars->enemies[enemy].col = next_col;
	render_enemy(vars, enemy);
	vars->map[vars->enemies[enemy].row][vars->enemies[enemy].col] = 'N';
}
// Try to move in the same direction and Try to move in the new direction
//if not Stay in the same position

void	move_enemy(t_vars *vars, int enemy)
{
	int	next_row;
	int	next_col;

	if (end_game(vars))
		return ;
	next_row = vars->enemies[enemy].row;
	next_col = vars->enemies[enemy].col;
	get_enemy_next_move(vars->enemy_dir[enemy], &next_row, &next_col);
	if (!enemy_valid_move(vars, next_row, next_col))
	{
		vars->enemy_dir[enemy] = rand() % DIRS;
		next_row = vars->enemies[enemy].row;
		next_col = vars->enemies[enemy].col;
		get_enemy_next_move(vars->enemy_dir[enemy], &next_row, &next_col);
		if (!enemy_valid_move(vars, next_row, next_col))
		{
			render_enemy(vars, enemy);
			return ;
		}
	}
	update_enemy_position(vars, enemy, next_row, next_col);
}
