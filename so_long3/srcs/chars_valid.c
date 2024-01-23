/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:14 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:15 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_multiple_player_error(void)
{
	ft_error("There is more than one player on the map\n");
	return (FALSE);
}

static int	get_result(t_vars *vars, int found_e, int found_p)
{
	if (found_e && found_p && vars->n_collect)
		return (TRUE);
	if (!found_e)
		ft_error("There is no exit point in the map\n");
	else if (!found_p)
		ft_error("There is no player position in the map\n");
	else if (!vars->n_collect)
		ft_error("There are no collectibles in the map\n");
	return (FALSE);
}

int	process_map_character(t_vars *vars,
	t_coord *coord, int *found_e, int *found_p)
{
	int	row;
	int	col;

	row = coord->row;
	col = coord->col;
	if (vars->map[row][col] == 'E')
	{
		if (*found_e)
			return (handle_multiple_exit_error());
		*found_e = TRUE;
		vars->exit = (t_coord){row, col};
	}
	else if (vars->map[row][col] == 'P')
	{
		if (*found_p)
			return (handle_multiple_player_error());
		*found_p = TRUE;
		vars->player = (t_coord){row, col};
		vars->player_last = (t_coord){row, col};
	}
	else if (vars->map[row][col] == 'C')
		vars->n_collect++;
	else if (vars->map[row][col] != '1' && vars->map[row][col] != '0')
		return (handle_invalid_character_error());
	return (TRUE);
}

int	is_chars_valid(t_vars *vars)
{
	t_coord	coord;
	int		found_e;
	int		found_p;

	found_e = 0;
	found_p = 0;
	vars->n_collect = 0;
	coord.row = 0;
	while (coord.row < vars->map_height)
	{
		coord.col = 0;
		while (coord.col < vars->map_width)
		{
			if (!process_map_character(vars, &coord, &found_e, &found_p))
			{
				return (FALSE);
			}
			coord.col++;
		}
		coord.row++;
	}
	return (get_result(vars, found_e, found_p));
}
