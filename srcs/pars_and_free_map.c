/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_and_free_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:48 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:49 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map_height)
		free(vars->map[i++]);
	free(vars->map);
	vars->map = NULL;
}

void	free_visited(char **visited, int map_height)
{
	int	i;

	i = 0;
	while (i < map_height)
		free(visited[i++]);
	free(visited);
}

void	free_matrix(char **matrix, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(matrix[i++]);
	free(matrix);
}
//line 41 : Read each line of the map file and store it in the matrix//

int	read_line(char **matrix, int *map_height, int fd)
{
	int	i;

	i = 0;
	while (i < *map_height)
	{
		matrix[i] = get_next_line(fd);
		if (matrix[i] == NULL)
		{
			close(fd);
			free_matrix(matrix, i);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

/**
 * Parses the map from the given file path and returns a 2D array of characters.
 * 
 * @param path The file path of the map file.
 * @param map_height Pointer to an integer to store the height of the map.
 * @return A 2D array of characters representing the parsed map.
 */
char	**parse_map(char *path, int *map_height)
{
	char	**matrix;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	*map_height = counting_lines(fd);
	close(fd);
	matrix = (char **)malloc((size_t)(*map_height) * sizeof(char *));
	if (!matrix)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(matrix);
		return (NULL);
	}
	if (read_line(matrix, map_height, fd) == FALSE)
		return (NULL);
	close(fd);
	return (matrix);
}
