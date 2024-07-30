/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:30:47 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 10:03:56 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	scale_list(t_fdf *box)
{
	t_point	*tmp;

	tmp = box->point;
	while (box->point)
	{
		ft_prepar_point(box->point, box, 0.5);
		ft_prepar_point_d(box->point, box, 0.5);
		ft_prepar_point_c(box->point, box, 0.5);
		box->point = box->point->next;
	}
	box->point = tmp;
}

void	ft_prepar_point(t_point *point, t_fdf *box, float z)
{
	int		scale;
	int		x_offset;
	int		y_offset;

	scale = min(HEIGHT / (box->nb_line + 1),
			WIDTH / (box->line_length + 1)) * z;
	point->x *= scale;
	point->y *= scale;
	point->z *= scale;
	iso(point);
	x_offset = (WIDTH - (box->line_length * scale * cos(0.523599)
				+ box->nb_line * scale * sin(0.7))) / 2;
	y_offset = (HEIGHT - (box->line_length * scale * sin(0.7)
				+ box->nb_line * scale * cos(0.523599))) / 2;
	x_offset += 300;
	y_offset += 100;
	point->x += x_offset;
	point->y += y_offset;
}

void	ft_prepar_point_c(t_point *point, t_fdf *box, float z)
{
	int		scale;
	int		x_offset;
	int		y_offset;

	scale = min(HEIGHT / (box->nb_line + 1),
			WIDTH / (box->line_length + 1)) * z;
	point->x_c *= scale;
	point->y_c *= scale;
	point->z *= scale;
	x_offset = (WIDTH - (box->line_length * scale * cos(0.523599)
				+ box->nb_line * scale * sin(0.7))) / 2;
	y_offset = (HEIGHT - (box->line_length * scale * sin(0.7)
				+ box->nb_line * scale * cos(0.523599))) / 2;
	x_offset += 300;
	y_offset += 100;
	point->x_c += x_offset;
	point->y_c += y_offset;
}

void	ft_prepar_point_d(t_point *point, t_fdf *box, float z)
{
	int		scale;
	int		x_offset;
	int		y_offset;

	scale = min(HEIGHT / (box->nb_line + 1),
			WIDTH / (box->line_length + 1)) * z;
	point->x_d *= scale;
	point->y_d *= scale;
	point->z *= scale;
	iso_d(point);
	x_offset = (WIDTH - (box->line_length * scale * cos(0.523599)
				+ box->nb_line * scale * sin(0.7))) / 2;
	y_offset = (HEIGHT - (box->line_length * scale * sin(0.7)
				+ box->nb_line * scale * cos(0.523599))) / 2;
	x_offset += 300;
	y_offset += 100;
	point->x_d += x_offset;
	point->y_d += y_offset;
}
