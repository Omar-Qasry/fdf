/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_and_draw_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:10:04 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/28 10:15:39 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_hook(int keycode, t_fdf *box)
{
	if (keycode == ESC)
		ft_destory(box);
	else if(keycode == paint_all)
		ft_new_color(box);
	else if(keycode == paint_z)
		ft_paint_z(box);
	else if(keycode == paint_low_z)
		ft_paint_low_z(box);
	else if(keycode == paint_ba)
		ft_paint_all(box);
	else if(keycode == up)
		translate(box, -2);
	else if(keycode == down)
		translate(box, 2);
	else if(keycode == right)
		translate(box, 1);
	else if(keycode == Left)
		translate(box, -1);
	else if (keycode == resset)
		davinchi(box);
	else if (keycode == conic)
		ft_conic(box);
	printf("%d\n", keycode);
	return (0);
}

void	ft_draw_x_lines(t_fdf box, int x, int p)
{
	int	j;

	j = 0;
	while (box.point && box.point->next)
	{
		if (j >= (box.line_length - 1))
		{
			j = 0;
			box.point = box.point->next;
			continue ;
		}
		else
			j++;
		if (p == -3)
		{
			if (box.point->z > 5)
				box.var.color = color_gradient(&box, x);
			else
				box.var.color = box.point->color;
		}
		else if (p == -2)
		{
			if (box.point->z < 5)
				box.var.color = color_gradient(&box, x);
			else
				box.var.color = box.point->color;
		}
		else if (p == -1)
			box.var.color = box.point->color;
		ft_draw_line(*box.point, *box.point->next, &box);
		box.point = box.point->next;
	}
	mlx_put_image_to_window(box.mlx_conect, box.mlx_win, box.img.mlx_img, 0, 0);
}

void	ft_draw_y_lines(t_fdf box, int x, int p)
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
		if (p == -3)
		{
			if (box.point->z > 5)
				box.var.color = color_gradient(&box, x);
			else
				box.var.color = box.point->color;
		}
		else if (p == -2)
		{
			if (box.point->z < 5)
				box.var.color = color_gradient(&box, x);
			else
				box.var.color = box.point->color;
		}
		else if (p == 0)
			box.var.color = color_gradient(&box, x);
		else if (p == -1)
			box.var.color = box.point->color;
		ft_draw_line(*box.point, *tmp, &box);
		tmp = tmp->next;
		box.point = box.point->next;
	}
	mlx_put_image_to_window(box.mlx_conect, box.mlx_win, box.img.mlx_img, 0, 0);
}

void	scale_list(t_fdf *box)
{
	t_point	*tmp;

	tmp = box->point;
	while (box->point)
	{
		ft_prepar_point(box->point, box);
		box->point = box->point->next;
	}
	box->point = tmp;
}
void	davinchi(t_fdf	*box)
{
	color_back(box, 0);
	ft_draw_x_lines(*box, -1, -1);
	ft_draw_y_lines(*box, -1, -1);
}
void	ft_paint_low_z(t_fdf *box)
{
	static int	i;

	if (i >= 8)
		i = 0;
	color_back(box, 0);
	ft_draw_x_lines(*box, i, -2);
	ft_draw_y_lines(*box, i, -2);
}
void	ft_paint_z(t_fdf *box)
{
	static int i;

	if (i >= 8)
		i = 0;
	color_back(box, 0);
	ft_draw_x_lines(*box, i, -3);
	ft_draw_y_lines(*box, i, -3);
}
void	ft_new_color(t_fdf	*box)
{
	static int i;

	if (i >= 8)
		i = 0;
	color_back(box, 0);
	ft_draw_x_lines(*box, i, 0);
	ft_draw_y_lines(*box, i, 0);
	i++;
}
void	ft_paint_all(t_fdf *box)
{
	color_back(box, 1);
	ft_draw_x_lines(*box, -1, -1);
	ft_draw_y_lines(*box, -1, -1);
}
void	translate(t_fdf	*box, int x)
{
	t_point	*tmp;

	tmp = box->point;
	while (box->point)
	{
		if (x == 1)
			box->point->x += 100;
		else if (x == -1)
			box->point->x -= 100;
		else if (x == 2)
			box->point->y += 50;
		else if (x == -2)
			box->point->y -= 50;
		box->point = box->point->next;
	}
	box->point = tmp;
	color_back(box, 0);
	ft_draw_x_lines(*box, -1, -1);
	ft_draw_y_lines(*box, -1, -1);
}
void	ft_conic(t_fdf *box)
{
	t_point	*tmp;

	tmp = box->point;
	while (box->point)
	{
		iso_2(box->point);
		box->point = box->point->next;
	}
	box->point = tmp;
	davinchi(box);
}
void	ft_mlx_and_draw(t_fdf *box)
{
	box->mlx_conect = mlx_init();
	box->mlx_win = mlx_new_window(box->mlx_conect, WIDTH, HEIGHT, box->maps_name);
	box->img.mlx_img = mlx_new_image(box->mlx_conect, WIDTH, HEIGHT);
	box->img.mlx_data = mlx_get_data_addr(box->img.mlx_img, &box->img.bits_per_pixel, &box->img.win_lenth, &box->img.endian);
	scale_list(box);
	davinchi(box);
	mlx_hook(box->mlx_win, RED_X, 0, ft_destory, box);
	mlx_key_hook(box->mlx_win, key_hook, box);
	mlx_loop(box->mlx_conect);
}
