/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:59 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:39:00 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// Dummy functions to prevent compilation error on MacOS
#ifdef __APPLE__

int	mlx_loop_end(void *mlx_ptr)
{
	(void)mlx_ptr;
	return (1);
}

int	mlx_destroy_display(void *mlx_ptr)
{
	(void)mlx_ptr;
	return (1);
}
#endif

long long	current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

int	check_extension(char *file_name)
{
	int		len;
	char	*start;
	int		ext_len;

	ext_len = ft_strlen(FILE_EXT);
	len = ft_strlen(file_name);
	start = &file_name[len - ext_len];
	if (ft_strncmp(start, FILE_EXT, ext_len) == 0)
		return (TRUE);
	return (FALSE);
}

void	ft_error(const char *msg)
{
	ft_printf("Error\n");
	ft_printf(msg);
}
