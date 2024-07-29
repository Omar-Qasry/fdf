/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_and_draw_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:10:04 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/29 12:05:32 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
void	go_back(t_fdf *box)
{
	t_point	*tmp;
	t_point	*tmp2;

	tmp = box->point;
	tmp2 = box->orijinal;
	while (tmp != NULL && tmp2 != NULL)
	{
		tmp->x = tmp2->x;
		tmp->y = tmp2->y;
		tmp->z = tmp2->z;
		tmp->color = tmp2->color;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
}
void	go_back_zoom(t_fdf *box)
{
	t_point	*tmp;
	t_point	*tmp2;

	tmp = box->point;
	tmp2 = box->zoom;
	while (tmp != NULL && tmp2 != NULL)
	{
		tmp->x = tmp2->x;
		tmp->y = tmp2->y;
		tmp->z = tmp2->z;
		tmp->color = tmp2->color;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
}
void	restor(t_fdf *box)
{
	go_back(box);
	color_back(box, 0);
	ft_draw_x_lines(*box, box->orijinal, -1, -1);
	ft_draw_y_lines(*box, box->orijinal, -1, -1);
}
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
		restor(box);
	else if (keycode == minus)
	{
		box->zoom_s *= 0.9;
		ft_zoum_min(box);
	}
	else if (keycode == plus)
	{
		box->zoom_s *= 1.1;
		ft_zoum_up(box);
	}
	else if (keycode == prajection)
		make_conic(box);
	printf("%d\n", keycode);
	return (0);
}

void	ft_draw_x_lines(t_fdf box,t_point *point, int x, int p)
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

void	ft_draw_y_lines(t_fdf box,t_point *point,int x, int p)
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

void	scale_list(t_fdf *box, int x)
{
	t_point	*tmp;

	if (x == 0)
	{
		tmp = box->point;
		while (box->point)
		{
			ft_prepar_point(box->point,box, 0, 0.4);
			box->point = box->point->next;
		}
		box->point = tmp;
	}
	else if (x == 1)
	{
		tmp = box->orijinal;
		while (box->orijinal)
		{
			ft_prepar_point(box->orijinal,box, 0, 0.4);
			box->orijinal = box->orijinal->next;
		}
		box->orijinal = tmp;
	}
}
void	conic_prooject(t_fdf *box)
{
	t_point	*tmp;

	tmp = box->conic;
	while (box->conic)
	{
		ft_prepar_point(box->conic,box, 1, 0.4);
		box->conic = box->conic->next;
	}
	box->conic = tmp;
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
	ft_draw_x_lines(*box,box->point, -1, -1);
	ft_draw_y_lines(*box,box->point, -1, -1);
}

void	ft_mlx_and_draw(t_fdf *box)
{
	box->mlx_conect = mlx_init();
	box->mlx_win = mlx_new_window(box->mlx_conect, WIDTH, HEIGHT, box->maps_name);
	box->img.mlx_img = mlx_new_image(box->mlx_conect, WIDTH, HEIGHT);
	box->img.mlx_data = mlx_get_data_addr(box->img.mlx_img, &box->img.bits_per_pixel, &box->img.win_lenth, &box->img.endian);
	box->orijinal = ft_point_copy(box->point);
	box->conic = ft_point_copy(box->point);
	box->zoom = ft_point_copy(box->point);
	box->zoom_s = 0.5;
	scale_list(box, 0);
	scale_list(box, 1);
	conic_prooject(box);
	davinchi(box);
	mlx_hook(box->mlx_win, RED_X, 0, ft_destory, box);
	mlx_key_hook(box->mlx_win, key_hook, box);
	mlx_loop(box->mlx_conect);
}
