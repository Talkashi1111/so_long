/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_animation_update.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:04 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:43:56 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//Length of the sequence 0,1,2,3,2,1,0,1,2,3,2,1,0,...
//Invert the index for the second half of the sequence
int	get_mushroom_index(int frame_count)
{
	int	index;
	int	sequence_length;

	sequence_length = 6;
	index = frame_count % sequence_length;
	if (index > 3)
		index = 6 - index;
	return (index);
}

void	render_collectibles(t_vars *vars, int mushroom_img_idx)
{
	int	mushroom;
	int	x;
	int	y;

	mushroom = 0;
	while (mushroom < vars->n_collect)
	{
		x = vars->collectibles[mushroom].col * vars->wall_width;
		y = vars->collectibles[mushroom].row * vars->wall_height;
		if (vars->collectibles[mushroom].row != -1)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->mushrooms[mushroom_img_idx], x, y);
		}
		mushroom++;
	}
}

void	random_enemy_direction_and_move(t_vars *vars)
{
	int	enemy;

	enemy = 0;
	while (enemy < vars->n_enemies)
	{
		if (vars->enemy_dir[enemy] == -1)
			vars->enemy_dir[enemy] = rand() % DIRS;
		move_enemy(vars, enemy);
		enemy++;
	}
}

int	update_frame(t_vars *vars)
{
	int	mushroom_img_idx;

	if (vars->map == NULL)
		return (OK);
	if (end_game(vars))
		return (OK);
	if (current_time_ms() - vars->last_measured_ms < FRAME_RATE_MS)
		return (OK);
	vars->last_measured_ms = current_time_ms();
	vars->frame_count = (vars->frame_count + 1) % 180;
	if (vars->frame_count % 45 == 0)
		random_enemy_direction_and_move(vars);
	if (vars->frame_count % 15 == 0)
	{
		mushroom_img_idx = get_mushroom_index(vars->frame_count / 15);
		render_collectibles(vars, mushroom_img_idx);
	}
	return (OK);
}
