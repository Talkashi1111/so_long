/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:19 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:37:20 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to check if there are any players
// or enemies in the surrounding cells
int	has_close_players_or_enemies(t_vars *vars, int row, int col)
{
	int	r;
	int	c;

	r = row - ENEMY_RADIUS;
	if (r < 0)
		r = 0;
	while (r <= row + ENEMY_RADIUS && r < vars->map_height)
	{
		c = col - ENEMY_RADIUS;
		if (c < 0)
			c = 0;
		while (c <= col + ENEMY_RADIUS && c < vars->map_width)
		{
			if (vars->map[r][c] == 'P' || vars->map[r][c] == 'N')
			{
				return (TRUE);
			}
			c++;
		}
		r++;
	}
	return (FALSE);
}

// Initialize rand() with a seed value
void	rand_enemies(t_vars *vars)
{
	int	row;
	int	col;
	int	i;

	srand(time(NULL));
	i = 0;
	while (i < MAX_TRIES)
	{
		row = rand() % vars->map_height;
		col = rand() % vars->map_width;
		if (vars->map[row][col] == '0' &&
			!has_close_players_or_enemies(vars, row, col))
		{
			vars->map[row][col] = 'N';
			vars->n_enemies++;
		}
		i++;
	}
}

int	init_enemies(t_vars *vars)
{
	rand_enemies(vars);
	if (vars->n_enemies == 0)
		return (TRUE);
	vars->enemies = malloc(sizeof(t_coord) * vars->n_enemies);
	if (!vars->enemies)
	{
		ft_error("Enemies allocation error\n");
		return (FALSE);
	}
	vars->enemy_dir = malloc(sizeof(int) * vars->n_enemies);
	if (!vars->enemy_dir)
	{
		ft_error("Enemies directions allocation error\n");
		return (FALSE);
	}
	return (TRUE);
}
