/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:26:37 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 10:05:38 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	translate(t_fdf	*box, int x)
{
	t_point	*tmp;

	tmp = box->point;
	while (box->point)
	{
		if (x == 1)
			box->point->x += 100;
		else if (x == -1)
			box->point->x -= 100;
		else if (x == 2)
			box->point->y += 50;
		else if (x == -2)
			box->point->y -= 50;
		box->point = box->point->next;
	}
	box->point = tmp;
	davinci(box);
}
