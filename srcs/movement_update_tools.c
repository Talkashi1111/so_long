/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_update_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:43 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:44 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// Check if the game is won or the game is lost//
int	end_game(t_vars *vars)
{
	if (vars->collected == vars->n_collect
		&& vars->player.row == vars->exit.row
		&& vars->player.col == vars->exit.col)
	{
		return (TRUE);
	}
	if (vars->map[vars->player.row][vars->player.col] == 'N')
	{
		ft_put_you_lose(vars);
		return (TRUE);
	}
	return (FALSE);
}

void	get_next_move(int dir, int *row, int *col)
{
	if (dir == KEY_UP)
		(*row)--;
	else if (dir == KEY_DOWN)
		(*row)++;
	else if (dir == KEY_RIGHT)
		(*col)++;
	else if (dir == KEY_LEFT)
		(*col)--;
}

int	valid_move(t_vars *vars, int keycode)
{
	int	next_row;
	int	next_col;

	next_row = vars->player.row;
	next_col = vars->player.col;
	get_next_move(keycode, &next_row, &next_col);
	if (next_row < 0 || next_row >= vars->map_height)
		return (FALSE);
	if (next_col < 0 || next_col >= vars->map_width)
		return (FALSE);
	if (vars->map[next_row][next_col] == '1')
		return (FALSE);
	return (TRUE);
}

void	update_collectible(t_vars *vars)
{
	int	i;

	i = 0;
	vars->map[vars->player.row][vars->player.col] = '0';
	vars->collected++;
	while (i < vars->n_collect)
	{
		if (vars->collectibles[i].row == vars->player.row
			&& vars->collectibles[i].col == vars->player.col)
		{
			vars->collectibles[i] = (t_coord){-1, -1};
			break ;
		}
		i++;
	}
}

void	move(t_vars *vars, int keycode)
{
	int	next_row;
	int	next_col;

	next_row = vars->player.row;
	next_col = vars->player.col;
	get_next_move(keycode, &next_row, &next_col);
	vars->player_last = vars->player;
	vars->player = (t_coord){next_row, next_col};
	if (vars->map[vars->player.row][vars->player.col] == 'C')
		update_collectible(vars);
}
