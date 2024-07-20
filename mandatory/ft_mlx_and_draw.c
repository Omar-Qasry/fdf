/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_and_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:10:04 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/19 23:52:55 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_fdf *box)
{
	int	previous_x;
	int	previous_y;
	int	previous_z;
	int	previous_x2;
	int	previous_y2;
	int	previous_z2;

	previous_x = box->var.x;
	previous_x2 = box->var.x2;
	previous_y = box->var.y;
	previous_y2 = box->var.y2;
	previous_z = box->var.z;
	previous_z2 = box->var.z2;
	box->var.x = (previous_x - previous_y) * cos(0.523599);
	box->var.y = (previous_x + previous_y) * sin(0.8) - previous_z;
	box->var.x2 = (previous_x2 - previous_y2) * cos(0.523599);
	box->var.y2 = (previous_x2 + previous_y2) * sin(0.8) - previous_z2 ;
}

void	ft_prepar_point(t_point x1, t_point x2, t_fdf *box)
{
	int	scale;

	if (box->line_length > box->nb_line)
		scale = (HEIGHT / box->nb_line) / 4;
	else
		scale = (WIDTH / box->line_length) / 4;
	box->var.x = x1.x * scale;
	box->var.y = x1.y * scale;
	box->var.z = x1.z * scale;
	box->var.x2 = x2.x * scale;
	box->var.y2 = x2.y * scale;
	box->var.z2 = x2.z * scale;
	iso(box);
	box->var.x += (WIDTH - (box->line_length * scale) / 4) / 2;
	box->var.x2 += (WIDTH - (box->line_length * scale) / 4) / 2;
	box->var.y += (HEIGHT - (box->nb_line * scale) / 2) / 4;
	box->var.y2 += (HEIGHT - (box->nb_line * scale) / 2) / 4;
	box->var.z += (HEIGHT - (box->nb_line * scale) / 4) / 2;
	box->var.z2 += (HEIGHT - (box->nb_line * scale) / 4) / 2;
}

void	ft_draw_x_lines(t_fdf box)
{
	while (box.point && box.point->next)
	{
		ft_prepar_point(*box.point, *box.point->next, &box);
		if (box.point->x >= box.line_length - 1)
		{
			box.point = box.point->next;
			continue ;
		}
		box.var.color = box.point->color;
		ft_draw_line(&box);
		box.point = box.point->next;
	}
}

void	ft_draw_y_lines(t_fdf box)
{
	t_point	*tmp;
	int		i;

	i = 0;
	tmp = box.point;
	while (i < box.line_length)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		ft_prepar_point(*box.point, *tmp, &box);
		box.var.color = box.point->color;
		ft_draw_line(&box);
		tmp = tmp->next;
		box.point = box.point->next;
	}
}

int	ft_destory(t_fdf *box)
{
	mlx_destroy_image(box->mlx.mlx_conect, box->mlx.mlx_img);
	mlx_destroy_window(box->mlx.mlx_conect, box->mlx.mlx_win);
	// ft_lstclear(box);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_fdf *box)
{
	if (keycode == ESC)
		ft_destory(box);
	return (0);
}

void	ft_mlx_and_draw(t_fdf	*box)
{
	t_point		*tmp;

	tmp = box->point;
	box->mlx.mlx_conect = mlx_init();
	box->mlx.mlx_win
		= mlx_new_window(box->mlx.mlx_conect, WIDTH, HEIGHT, box->maps_name);
	box->mlx.mlx_img
		= mlx_new_image(box->mlx.mlx_conect, WIDTH, HEIGHT);
	mlx_put_image_to_window
	(box->mlx.mlx_conect, box->mlx.mlx_win, box->mlx.mlx_img, WIDTH, HEIGHT);
	ft_draw_y_lines(*box);
	ft_draw_x_lines(*box);
	mlx_hook(box->mlx.mlx_win, RED_X, 0, ft_destory, box);
	mlx_key_hook(box->mlx.mlx_win, key_hook, box);
	mlx_loop(box->mlx.mlx_conect);
}
