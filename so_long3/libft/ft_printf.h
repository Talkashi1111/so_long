/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:55:18 by tkashi            #+#    #+#             */
/*   Updated: 2023/11/05 20:12:39 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_count
{
	int		count;
	int		error;
}	t_count;

void	ft_print_d(int n, t_count *stcount);	
void	ft_print_x(unsigned int decimal, char flag, t_count *stcount);
void	ft_print_s(char *s, t_count *stcount);
void	ft_print_u(unsigned int n, t_count *stcount);
void	ft_print_c(char c, t_count *stcount);
void	ft_print_p(unsigned long addr, t_count *stcount);
#endif
