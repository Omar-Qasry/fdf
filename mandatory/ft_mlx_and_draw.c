/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_and_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:10:04 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/24 10:44:06 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_fdf *box)
{
	if (keycode == ESC)
		ft_destory(box);
	return (0);
}

void	ft_draw_x_lines(t_fdf box)
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
		box.var.color = box.point->color;
		ft_draw_line(*box.point, *box.point->next, &box);
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
		box.var.color = box.point->color;
		ft_draw_line(*box.point, *tmp, &box);
		tmp = tmp->next;
		box.point = box.point->next;
	}
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

void	ft_mlx_and_draw(t_fdf *box)
{
	box->mlx_conect = mlx_init();
	box->mlx_win = mlx_new_window(box->mlx_conect, WIDTH, HEIGHT, box->maps_name);
	box->img.mlx_img = mlx_new_image(box->mlx_conect, WIDTH, HEIGHT);
	box->img.mlx_data = mlx_get_data_addr(box->img.mlx_img, &box->img.bits_per_pixel, &box->img.win_lenth, &box->img.endian);
	scale_list(box);
	color_back(box);
	ft_draw_x_lines(*box);
	ft_draw_y_lines(*box);
	mlx_put_image_to_window(box->mlx_conect, box->mlx_win, box->img.mlx_img, 0, 0);
	mlx_hook(box->mlx_win, RED_X, 0, ft_destory, box);
	mlx_key_hook(box->mlx_win, key_hook, box);
	mlx_loop(box->mlx_conect);
}
