/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:11:22 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/30 09:35:48 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_push(t_point **point, t_var *var)
{
	t_point	*new_node;

	new_node = ft_lstnew(var);
	if (!new_node)
		return ;
	ft_lstadd_back(point, new_node);
}
