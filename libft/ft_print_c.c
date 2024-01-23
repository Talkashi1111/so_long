/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:33:31 by tkashi            #+#    #+#             */
/*   Updated: 2023/11/05 19:34:55 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

void	ft_print_c(char c, t_count *stcount)
{
	if (write(1, &c, 1) < 0)
		stcount->error += 1;
	else
		stcount->count += 1;
}
