/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:28:56 by tkashi            #+#    #+#             */
/*   Updated: 2023/11/01 18:47:08 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_libft	*ft_lstnew(void *content)
{
	t_libft	*node;

	node = (t_libft *)malloc(sizeof(t_libft));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
