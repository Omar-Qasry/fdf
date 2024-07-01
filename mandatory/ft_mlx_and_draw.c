/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_and_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:10:04 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/01 12:13:42 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_and_draw(t_fdf	*box, t_mlx	*mlx)
{
	mlx->mlx_conect = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_conect, WIDTH, HEIGHT, box->maps_name);
	mlx->mlx_img = mlx_new_image(mlx->mlx_conect, WIDTH, HEIGHT);
	box->var.x = 0;
	box->var.y = 0;
	while (box->var.y < box->nb_line * 50)
	{
		box->var.x = 0;
		while (box->var.x < box->nb_line * 50 - 50)
		{
			mlx_pixel_put(mlx->mlx_conect, mlx->mlx_win, box->var.x, box->var.y, 0X04FFFF);
			box->var.x++;
		}
		box->var.y += 50;
	}
	box->var.x = 0;
	box->var.y = 0;
	while (box->var.y < box->nb_line * 50)
	{
		box->var.x = 0;
		while (box->var.x < box->nb_line * 50 - 50)
		{
			mlx_pixel_put(mlx->mlx_conect, mlx->mlx_win, box->var.y, box->var.x, 0XFF0000);
			box->var.x++;
		}
		box->var.y += 50;
	}
	mlx_loop(mlx->mlx_conect);
}
