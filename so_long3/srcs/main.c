/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:25 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:37:26 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx_window(t_vars *vars)
{
	int		x;
	int		y;

	x = vars->map_width * vars->wall_width;
	y = vars->map_height * vars->wall_height;
	vars->win = mlx_new_window(vars->mlx, x, y, "So Long");
	if (vars->win == NULL)
		return (FALSE);
	return (TRUE);
}

void	destroy_mlx_display(t_vars *vars)
{
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

int	prepare_game_error(t_vars *vars)
{
	if (!prepare_game(vars))
	{
		ft_close(vars);
		destroy_mlx_display(vars);
		return (ALLOC_ERROR);
	}
	return (OK);
}

// In MacOS mlx_loop never returns
int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		ret;

	if (argc != 2)
	{
		ft_print_usage(argv[0]);
		return (ARG_ERROR);
	}
	ret = init_game(argv[1], &vars);
	if (ret != OK)
		return (ret);
	ret = prepare_game_error(&vars);
	if (ret != OK)
		return (ret);
	mlx_key_hook(vars.win, key_release, &vars);
	mlx_hook(vars.win, DESTROY_NOTIFY, 0, ft_close, &vars);
	mlx_hook(vars.win, KEY_PRESS, 1L << 0, key_press, &vars);
	mlx_loop_hook(vars.mlx, update_frame, &vars);
	mlx_loop(vars.mlx);
	destroy_mlx_display(&vars);
	return (OK);
}
