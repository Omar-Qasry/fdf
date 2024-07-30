/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_algo_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:50:20 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 08:38:58 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	ft_draw_x_lines(t_fdf box, t_point *point, int x, int p)
{
	int	j;

	j = 0;
	while (point && point->next)
	{
		if (j >= (box.line_length - 1))
		{
			j = 0;
			point = point->next;
			continue ;
		}
		else
			j++;
		if (p == -3)
		{
			if (point->z > 5)
				box.var.color = color_gradient(&box, x);
			else
				box.var.color = point->color;
		}
		else if (p == -2)
		{
			if (point->z < 5)
				box.var.color = color_gradient(&box, x);
			else
				box.var.color = point->color;
		}
		else if (p == -1)
			box.var.color = point->color;
		ft_draw_line(*point, *point->next, &box);
		point = point->next;
	}
	mlx_put_image_to_window(box.mlx_conect, box.mlx_win, box.img.mlx_img, 0, 0);
}

void	ft_draw_y_lines(t_fdf box, t_point *point, int x, int p)
{
	t_point	*tmp;
	int		i;

	i = 0;
	tmp = point;
	while (i < box.line_length)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (p == -3)
		{
			if (point->z > 5)
				box.var.color = color_gradient(&box, x);
			else
				box.var.color = point->color;
		}
		else if (p == -2)
		{
			if (point->z < 5)
				box.var.color = color_gradient(&box, x);
			else
				box.var.color = point->color;
		}
		else if (p == 0)
			box.var.color = color_gradient(&box, x);
		else if (p == -1)
			box.var.color = point->color;
		ft_draw_line(*point, *tmp, &box);
		tmp = tmp->next;
		point = point->next;
	}
	mlx_put_image_to_window(box.mlx_conect, box.mlx_win, box.img.mlx_img, 0, 0);
}
