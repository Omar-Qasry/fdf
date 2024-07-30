/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_and_draw_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:10:04 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 10:32:55 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_tranclate_hook(int keycode, t_fdf *box)
{
	if (keycode == UP)
		translate(box, -2);
	else if (keycode == DOWN)
		translate(box, 2);
	else if (keycode == RIGHT)
		translate(box, 1);
	else if (keycode == LEFT)
		translate(box, -1);
}

int	key_hook(int keycode, t_fdf *box)
{
	if (keycode == ESC)
		ft_destory(box);
	else if (keycode == UP || keycode == DOWN
		|| keycode == RIGHT || keycode == LEFT)
		ft_tranclate_hook(keycode, box);
	else if (keycode == PAINT_ALL)
		ft_new_color(box);
	else if (keycode == PAINT_Z)
		ft_paint_z(box);
	else if (keycode == PAINT_LOW_Z)
		ft_paint_low_z(box);
	else if (keycode == PAINT_BA)
		ft_paint_all(box);
	else if (keycode == RESSET)
		ft_restor(box);
	else if (keycode == MINUS)
		ft_zoum(box, '-');
	else if (keycode == PLUS)
		ft_zoum(box, '+');
	else if (keycode == PROJECTION)
		make_conic(box);
	return (0);
}

void	ft_mlx_and_draw(t_fdf *box)
{
	box->mlx_conect = mlx_init();
	box->mlx_win = mlx_new_window(box->mlx_conect,
			WIDTH, HEIGHT, box->maps_name);
	box->img.mlx_img = mlx_new_image(box->mlx_conect, WIDTH, HEIGHT);
	box->img.mlx_data = mlx_get_data_addr(box->img.mlx_img,
			&box->img.bits_per_pixel, &box->img.win_lenth, &box->img.endian);
	box->zoom_s = 0.5;
	make_x_y_copy(box);
	scale_list(box);
	davinci(box);
	mlx_hook(box->mlx_win, RED_X, 0, ft_destory, box);
	mlx_key_hook(box->mlx_win, key_hook, box);
	mlx_loop(box->mlx_conect);
}
