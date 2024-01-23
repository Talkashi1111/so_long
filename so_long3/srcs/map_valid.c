/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:38 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:39 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_int(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	handle_invalid_character_error(void)
{
	ft_error("Invalid character in the map\n");
	return (FALSE);
}

int	counting_lines(int fd)
{
	int		counter;
	char	*line;

	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	return (counter);
}

int	is_rect(char **mat, int map_height, int *map_width)
{
	int	i;

	*map_width = ft_strlen_int(mat[0]);
	i = 1;
	while (i < map_height)
	{
		if (ft_strlen_int(mat[i]) != *map_width)
		{
			ft_error("The map is not rectangular\n");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
/** @brief Allocates memory for the map, parses the map file, 
 * and performs various checks to validate the map.
 * @param path The path to the map file.
 * @param vars The structure containing variables related to the map.
 * @param check_extension Check if the file extension is valid
 */

void	alloc_map(char *path, t_vars *vars)
{
	if (!check_extension(path))
	{
		ft_error("Wrong file extension, should be .ber file\n");
		return ;
	}
	vars->map = parse_map(path, &vars->map_height);
	if (!vars->map
		|| !is_rect(vars->map, vars->map_height, &vars->map_width)
		|| !is_surrounded_by_walls(vars->map, vars->map_height, vars->map_width)
		|| !is_chars_valid(vars)
		|| !is_solvable(vars))
	{
		free_map(vars);
		vars->map = NULL;
		return ;
	}
}
