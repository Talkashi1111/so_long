/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:35:04 by tkashi            #+#    #+#             */
/*   Updated: 2023/11/05 19:47:47 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

void	ft_print_d(int n, t_count *stcount)
{
	if (n == -2147483648)
	{
		ft_print_s("-2147483648", stcount);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_print_c('-', stcount);
	}
	if (n < 10 && !stcount->error)
	{
		ft_print_c(n + '0', stcount);
		return ;
	}
	ft_print_d(n / 10, stcount);
	ft_print_c(n % 10 + '0', stcount);
}
