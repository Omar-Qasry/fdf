/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:33:41 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 11:43:05 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	go_back(t_fdf *box)
{
	t_point	*tmp3;

	tmp3 = box->point;
	while (tmp3)
	{
		tmp3->x = tmp3->x_d;
		tmp3->y = tmp3->y_d;
		tmp3->z = tmp3->z_d;
		tmp3 = tmp3->next;
	}
}

void	go_to_conic(t_fdf *box)
{
	t_point	*tmp2;

	tmp2 = box->point;
	while (tmp2)
	{
		tmp2->x = tmp2->x_c;
		tmp2->y = tmp2->y_c;
		tmp2->z = tmp2->z_z;
		tmp2 = tmp2->next;
	}
}

void	ft_restor(t_fdf *box)
{
	t_point			*tmp;

	tmp = box->point;
	go_to_zoom(box);
	while (box->point)
	{
		ft_prepar_point(box->point, box, 0.5);
		box->point = box->point->next;
	}
	box->point = tmp;
	davinci(box);
}

void	make_x_y_copy(t_fdf *box)
{
	t_point	*tmp;

	tmp = box->point;
	while (box->point)
	{
		box->point->x_d = box->point->x;
		box->point->y_d = box->point->y;
		box->point->z_d = box->point->z;
		box->point->x_c = box->point->x;
		box->point->y_c = box->point->y;
		box->point->x_z = box->point->x;
		box->point->y_z = box->point->y;
		box->point->z_z = box->point->z;
		box->point = box->point->next;
	}
	box->point = tmp;
}
