/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:57:03 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 10:57:40 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	update_drawing_coordinates(t_point *x1, t_fdf *box)
{
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
}

void	initialize_draw_params(t_point *x1, t_point *x2, t_fdf *box)
{
	box->draw.dx = abs(x2->x - x1->x);
	box->draw.dy = abs(x2->y - x1->y);
	if (x1->x < x2->x)
		box->draw.sx = 1;
	else
		box->draw.sx = -1;
	if (x1->y < x2->y)
		box->draw.sy = 1;
	else
		box->draw.sy = -1;
	box->draw.error = box->draw.dx - box->draw.dy;
}

void	ft_draw_line(t_point x1, t_point x2, t_fdf *box)
{
	initialize_draw_params(&x1, &x2, box);
	while (1)
	{
		if (x1.x >= 0 && x1.y >= 0 && x1.x < WIDTH && x1.y < HEIGHT)
			my_pixel_put(x1.x, x1.y, box->var.color, box);
		if (x1.x == x2.x && x1.y == x2.y)
			break ;
		update_drawing_coordinates(&x1, box);
	}
}
