/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:33:02 by tkashi            #+#    #+#             */
/*   Updated: 2023/11/05 19:51:30 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static void	format_check(const char *fmt, va_list args, t_count *stcount)
{
	if ('d' == *fmt || 'i' == *fmt)
		ft_print_d(va_arg(args, int), stcount);
	else if (*fmt == 's')
		ft_print_s(va_arg(args, char *), stcount);
	else if (*fmt == 'c')
		ft_print_c(va_arg(args, int), stcount);
	else if (*fmt == 'x' || *fmt == 'X')
		ft_print_x(va_arg(args, unsigned int), *fmt, stcount);
	else if (*fmt == 'u')
		ft_print_u(va_arg(args, unsigned int), stcount);
	else if ('p' == *fmt)
		ft_print_p(va_arg(args, unsigned long), stcount);
	else
	{
		ft_print_c('%', stcount);
		if (*fmt != '%')
			ft_print_c(*fmt, stcount);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_count	stcount;

	stcount.error = 0;
	stcount.count = 0;
	va_start(args, fmt);
	while (fmt && *fmt != '\0' && !stcount.error)
	{
		if (*fmt != '%')
			ft_print_c(*fmt, &stcount);
		else
		{
			if (*++fmt == '\0')
			{
				ft_print_c('%', &stcount);
				continue ;
			}
			format_check(fmt, args, &stcount);
		}
		fmt++;
	}
	va_end(args);
	if (stcount.error)
		return (-1);
	return (stcount.count);
}
