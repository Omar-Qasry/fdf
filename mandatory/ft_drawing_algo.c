/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:50:20 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/19 17:00:14 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_fdf *box)
{
	box->draw.dx = abs(box->var.x2 - box->var.x);
	box->draw.dy = abs(box->var.y2 - box->var.y);
	if (box->var.x < box->var.x2)
		box->draw.sx = 1;
	else
		box->draw.sx = -1;
	if (box->var.y < box->var.y2)
		box->draw.sy = 1;
	else
		box->draw.sy = -1;
	box->draw.error = box->draw.dx - box->draw.dy;
	while (1)
	{
		if (box->var.x >= 0 && box->var.y >= 0 && box->var.x < WIDTH && box->var.y < HEIGHT)
			mlx_pixel_put(box->mlx.mlx_conect, box->mlx.mlx_win, box->var.x, box->var.y, box->var.color);
		if (box->var.x == box->var.x2 && box->var.y == box->var.y2)
			break ;
		box->draw.e2 = 2 * box->draw.error;
		if (box->draw.e2 >= -box->draw.dy)
		{
			box->draw.error -= box->draw.dy;
			box->var.x += box->draw.sx;
		}
		if (box->draw.e2 <= box->draw.dx)
		{
			box->draw.error += box->draw.dx;
			box->var.y += box->draw.sy;
		}
	}
}
