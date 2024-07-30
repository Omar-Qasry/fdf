/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:33:41 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 08:47:48 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	go_back(t_fdf *box)
{
	t_point	*tmp;

	tmp = box->point;
	while (tmp)
	{
		tmp->x = tmp->x_d;
		tmp->y = tmp->y_d;
		tmp->z = tmp->z_z;
		tmp = tmp->next;
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
	go_back(box);
	mlx_clear_window(box->mlx_conect, box->mlx_win);
	color_back(box, 0);
	ft_draw_x_lines(*box, box->point, -1, -1);
	ft_draw_y_lines(*box, box->point, -1, -1);
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
