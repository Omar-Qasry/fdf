/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:23:50 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 12:02:44 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	go_to_zoom(t_fdf *box)
{
	t_point	*tmp3;

	tmp3 = box->point;
	while (tmp3)
	{
		tmp3->x = tmp3->x_z;
		tmp3->y = tmp3->y_z;
		tmp3->z = tmp3->z_z;
		tmp3 = tmp3->next;
	}
}

void	ft_zoum(t_fdf *box, int x)
{
	t_point			*tmp;

	tmp = box->point;
	if (x == '-')
	{
		if (box->nb_line > 130)
		{
			if (box->zoom_s <= 0.5)
				box->zoom_s = 0.5;
			else
			box->zoom_s *= 0.9;
		}
		else
			box->zoom_s *= 0.9;
	}
	else if (x == '+')
		box->zoom_s *= 1.1;
	go_to_zoom(box);
	while (box->point)
	{
		ft_prepar_point(box->point, box, box->zoom_s);
		box->point = box->point->next;
	}
	box->point = tmp;
	davinci(box);
}
