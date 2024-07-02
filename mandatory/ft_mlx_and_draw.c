/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_and_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:10:04 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/03 00:37:05 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	ft_draw_line(int x1, int x2, int y1,int y2, t_fdf *box)
{
	int	x;
	int	y;

	y = box->point->y;
	x = box->point->x;
	while (x < x2)
	{
		if (x/50 < box->line_length)
			mlx_pixel_put(box->mlx.mlx_conect, box->mlx.mlx_win, x+WIDTH/4, y1+HEIGHT/4, 0XFF0000);
		x++;
	}
	while(y < y2)
	{
		if (y/50 < box->nb_line)
			mlx_pixel_put(box->mlx.mlx_conect, box->mlx.mlx_win, x1+WIDTH/4, y+HEIGHT/4, 0X04FFFF);
		y++;
	}
}

void	ft_mlx_and_draw(t_fdf	*box)
{
	box->mlx.mlx_conect = mlx_init();
	box->mlx.mlx_win = mlx_new_window(box->mlx.mlx_conect, WIDTH, HEIGHT, box->maps_name);
	box->mlx.mlx_img = mlx_new_image(box->mlx.mlx_conect, WIDTH, HEIGHT);
	while (box->point && box->point->next)
	{
		ft_draw_line(box->point->x*50, box->point->next->x*50, box->point->y*50, box->point->next->y*50, box);
		box->point = box->point->next;
	}
	mlx_loop(box->mlx.mlx_conect);
}
