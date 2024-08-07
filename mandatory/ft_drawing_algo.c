/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:50:20 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/26 04:23:11 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_point *point)
{
	t_iso	iso;

	iso.previous_x = point->x;
	iso.previous_y = point->y;
	iso.previous_z = point->z;
	point->x = (iso.previous_x - iso.previous_y) * cos(0.523599);
	point->y = (iso.previous_x + iso.previous_y) * sin(0.8) - iso.previous_z;
}

void	ft_prepar_point(t_point *point, t_fdf *box)
{
	int		scale;
	int		x_offset;
	int		y_offset;

	if (box->nb_line >= 100)
		scale = min(HEIGHT
				/ (box->nb_line + 1), WIDTH / (box->line_length + 1)) / 2;
	if (box->nb_line < 100)
		scale = min(HEIGHT
				/ (box->nb_line + 1), WIDTH / (box->line_length + 1)) / 3;
	point->x *= scale ;
	point->y *= scale ;
	point->z *= scale;
	iso(point);
	x_offset = (WIDTH - (box->line_length * scale
				* cos(0.523599) + box->nb_line * scale * sin(0.8))) / 2;
	y_offset = (HEIGHT - (box->line_length * scale
				* sin(0.8) + box->nb_line * scale * cos(0.523599))) / 2;
	x_offset += 300;
	y_offset += 100;
	point->x += x_offset;
	point->y += y_offset;
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

int	draw_line_helper(t_point *x1, t_point *x2, t_fdf *box)
{
	if (x1->x >= 0 && x1->y >= 0 && x1->x < WIDTH && x1->y < HEIGHT)
		my_pixel_put(x1->x, x1->y, box->var.color, box);
	if (x1->x == x2->x && x1->y == x2->y)
		return (1);
	box->draw.e2 = 2 * box->draw.error;
	if (box->draw.e2 >= -box->draw.dy)
	{
		box->draw.error -= box->draw.dy;
		x1->x += box->draw.sx;
	}
	if (box->draw.e2 <= box->draw.dx)
	{
		box->draw.error += box->draw.dx;
		x1->y += box->draw.sy;
	}
	return (0);
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
		if (draw_line_helper(&x1, &x2, box))
			break ;
	}
}
