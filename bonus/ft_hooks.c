/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:49:03 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/29 11:40:11 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <math.h>

void	davinchi(t_fdf *box)
{
	color_back(box, 0);
	ft_draw_x_lines(*box,box->point, -1, -1);
	ft_draw_y_lines(*box,box->point, -1, -1);
}
void	ft_paint_low_z(t_fdf *box)
{
	static int	i;

	if (i >= 8)
		i = 0;
	color_back(box, 0);
	ft_draw_x_lines(*box,box->point, i, -2);
	ft_draw_y_lines(*box,box->point, i, -2);
}

void	ft_paint_z(t_fdf *box)
{
	static int i;

	if (i >= 8)
		i = 0;
	color_back(box, 0);
	ft_draw_x_lines(*box,box->point, i, -3);
	ft_draw_y_lines(*box,box->point, i, -3);
}
void	ft_new_color(t_fdf *box)
{
	static int i;

	if (i >= 8)
		i = 0;
	color_back(box, 0);
	ft_draw_x_lines(*box,box->point, i, 0);
	ft_draw_y_lines(*box, box->point,i, 0);
	i++;
}
void	ft_paint_all(t_fdf *box)
{
	color_back(box, 1);
	ft_draw_x_lines(*box,box->point, -1, -1);
	ft_draw_y_lines(*box, box->point,-1, -1);
}
void	make_conic(t_fdf *box)
{
	color_back(box, 0);
	ft_draw_x_lines(*box, box->conic, -1, -1);
	ft_draw_y_lines(*box, box->conic, -1, -1);
}
void	ft_zoum_min(t_fdf *box)
{
	t_point			*tmp;
	static float	z = 1.0;

	tmp = box->point;
	go_back_zoom(box);
	z *= 0.9;
	while (box->point)
	{
		ft_prepar_point(box->point, box, 0, z);
		box->point = box->point->next;
	}
	box->point = tmp;
	davinchi(box);
}
void	ft_zoum_up(t_fdf *box)
{
	t_point			*tmp;
	static float	z = 1.0;

	tmp = box->point;
	go_back_zoom(box);
	z *= 1.1;
	while (box->point)
	{
		ft_prepar_point(box->point, box, 0, z);
		box->point = box->point->next;
	}
	box->point = tmp;
	davinchi(box);
}
