/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:11:22 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/25 10:29:25 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_push(t_fdf *box)
{
	t_point	*new_node;

	new_node = ft_lstnew(&box->var);
	if (!new_node)
		return ;
	ft_lstadd_back(&box->point, new_node);
}
