/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_surrounded_by_walls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:46 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:37:47 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_row(char **mat, int row)
{
	int	col;

	col = 0;
	while (!(mat[row][col] == '\n' || mat[row][col] == '\0'))
	{
		if (mat[row][col] != '1')
			return (FALSE);
		col++;
	}
	return (TRUE);
}

static int	check_col(char **mat, int map_height, int col)
{
	int	row;

	row = 0;
	while (row < map_height)
	{
		if (mat[row][col] != '1')
			return (FALSE);
		row++;
	}
	return (TRUE);
}

int	is_surrounded_by_walls( char **mat, int map_height, int map_width)
{
	if (!check_row(mat, 0) || !check_row(mat, map_height - 1))
	{
		ft_error("Map is not serrounded by walls\n");
		return (FALSE);
	}
	if (!check_col(mat, map_height, 0)
		|| !check_col(mat, map_height, map_width - 1))
	{
		ft_error("Map is not serrounded by walls\n");
		return (FALSE);
	}
	return (TRUE);
}

int	handle_multiple_exit_error(void)
{
	ft_error("There is more than one exit on the map\n");
	return (FALSE);
}
