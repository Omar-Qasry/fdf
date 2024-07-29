/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_algo_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:50:20 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/29 17:46:11 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <math.h>

void	iso(t_point *point)
{
	t_iso	iso;

	iso.previous_x = point->x;
	iso.previous_y = point->y;
	iso.previous_z = point->z;
	point->x = (iso.previous_x - iso.previous_y) * cos(0.523599);
	point->y = (iso.previous_x + iso.previous_y) * sin(0.8) - iso.previous_z;
}
void	iso_d(t_point *point)
{
	t_iso	iso;

	iso.previous_x = point->x_d;
	iso.previous_y = point->y_d;
	iso.previous_z = point->z;
	point->x_d = (iso.previous_x - iso.previous_y) * cos(0.523599);
	point->y_d = (iso.previous_x + iso.previous_y) * sin(0.8) - iso.previous_z;
}

void	ft_prepar_point(t_point *point, t_fdf *box, float z)
{
	int		scale;
	int		x_offset;
	int		y_offset;

	scale = min(HEIGHT / (box->nb_line + 1), WIDTH / (box->line_length + 1)) * z;
	point->x *= scale;
	point->y *= scale;
	point->z *= scale;
	iso(point);
	x_offset = (WIDTH - (box->line_length * scale * cos(0.523599) + box->nb_line * scale * sin(0.7))) / 2;
	y_offset = (HEIGHT - (box->line_length * scale * sin(0.7) + box->nb_line * scale * cos(0.523599))) / 2;
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

	scale = min(HEIGHT / (box->nb_line + 1), WIDTH / (box->line_length + 1)) * z;
	point->x_c *= scale;
	point->y_c *= scale;
	point->z *= scale;
	x_offset = (WIDTH - (box->line_length * scale * cos(0.523599) + box->nb_line * scale * sin(0.7))) / 2;
	y_offset = (HEIGHT - (box->line_length * scale * sin(0.7) + box->nb_line * scale * cos(0.523599))) / 2;
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

	scale = min(HEIGHT / (box->nb_line + 1), WIDTH / (box->line_length + 1)) * z;
	point->x_d *= scale;
	point->y_d *= scale;
	point->z *= scale;
	iso_d(point);
	x_offset = (WIDTH - (box->line_length * scale * cos(0.523599) + box->nb_line * scale * sin(0.7))) / 2;
	y_offset = (HEIGHT - (box->line_length * scale * sin(0.7) + box->nb_line * scale * cos(0.523599))) / 2;
	x_offset += 300;
	y_offset += 100;
	point->x_d += x_offset;
	point->y_d += y_offset;
}
void	my_pixel_put(int x, int y, int color, t_fdf *box)
{
	char	*dst;

	if ((0 <= x && x < WIDTH) && (0 <= y && y < HEIGHT))
	{
		x *= (box->img.bits_per_pixel / 8);
		y *= box->img.win_lenth;
		dst = box->img.mlx_data + x + y;
		*(unsigned int *) dst = color;
	}
}

void	ft_draw_line(t_point x1, t_point x2, t_fdf *box)
{
	box->draw.dx = abs(x2.x - x1.x);
	box->draw.dy = abs(x2.y - x1.y);
	if (x1.x < x2.x)
		box->draw.sx = 1;
	else
		box->draw.sx = -1;
	if (x1.y < x2.y)
		box->draw.sy = 1;
	else
		box->draw.sy = -1;
	box->draw.error = box->draw.dx - box->draw.dy;
	while (1)
	{
		if (x1.x >= 0 && x1.y >= 0 && x1.x < WIDTH && x1.y < HEIGHT)
			my_pixel_put(x1.x, x1.y, box->var.color, box);
		if (x1.x == x2.x && x1.y == x2.y)
			break ;
		box->draw.e2 = 2 * box->draw.error;
		if (box->draw.e2 >= -box->draw.dy)
		{
			box->draw.error -= box->draw.dy;
			x1.x += box->draw.sx;
		}
		if (box->draw.e2 <= box->draw.dx)
		{
			box->draw.error += box->draw.dx;
			x1.y += box->draw.sy;
		}
	}
}
