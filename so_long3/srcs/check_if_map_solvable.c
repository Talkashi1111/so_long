/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_solvable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:33 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:37:34 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(t_vars *vars, int row, int col, t_dfs_vars *dfs_vars)
{
	if (dfs_vars->visited[row][col] == TRUE)
		return ;
	dfs_vars->visited[row][col] = TRUE;
	if (vars->map[row][col] == 'E')
		dfs_vars->found_exit = TRUE;
	if (vars->map[row][col] == 'C')
		dfs_vars->found_collectibles++;
	if (col + 1 < vars->map_width && vars->map[row][col + 1] != '1')
		dfs(vars, row, col + 1, dfs_vars);
	if (col - 1 >= 0 && vars->map[row][col - 1] != '1')
		dfs(vars, row, col - 1, dfs_vars);
	if (row + 1 < vars->map_height && vars->map[row + 1][col] != '1')
		dfs(vars, row + 1, col, dfs_vars);
	if (row - 1 >= 0 && vars->map[row - 1][col] != '1')
		dfs(vars, row - 1, col, dfs_vars);
}

static void	put_zero_in_col(int map_height, int map_width, char **visited)
{
	int	row;
	int	col;

	row = 0;
	while (row < map_height)
	{
		col = 0;
		while (col < map_width)
		{
			visited[row][col] = FALSE;
			col++;
		}
		row++;
	}
}

char	**create_visited(int map_height, int map_width)
{
	char	**visited;
	int		row;

	visited = (char **)malloc(map_height * sizeof(char *));
	if (!visited)
		return (NULL);
	row = 0;
	while (row < map_height)
	{
		visited[row] = (char *)malloc(map_width * sizeof(char));
		if (visited[row] == NULL)
		{
			free_visited(visited, row);
			return (NULL);
		}
		row++;
	}
	put_zero_in_col(map_height, map_width, visited);
	return (visited);
}

void	init_dfs_struct(t_dfs_vars *dfs_vars, char **visited)
{
	dfs_vars->found_exit = FALSE;
	dfs_vars->found_collectibles = 0;
	dfs_vars->visited = visited;
}

int	is_solvable(t_vars *vars)
{
	char		**visited;
	t_dfs_vars	dfs_vars;

	visited = create_visited(vars->map_height, vars->map_width);
	if (!visited)
	{
		ft_error("Couldn't allocate visited map\n");
		return (FALSE);
	}
	init_dfs_struct(&dfs_vars, visited);
	dfs(vars, vars->player.row, vars->player.col, &dfs_vars);
	free_visited(visited, vars->map_height);
	if (!dfs_vars.found_exit)
	{
		ft_error("The map is not solvable, exit unreachable\n");
		return (FALSE);
	}
	if (vars->n_collect != dfs_vars.found_collectibles)
	{
		ft_error("The map is not solvable,"
			"some of collectibles are unreachable\n");
		return (FALSE);
	}
	return (TRUE);
}
