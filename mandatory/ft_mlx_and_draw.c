/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_and_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:10:04 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/04 22:59:18 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	ft_draw_lines(int x1, int x2, int y1,int y2, t_fdf *box)
{
	while (box->point->x < x2)
	{
		if (box->point->x/50 < box->line_length)
			mlx_pixel_put(box->mlx.mlx_conect, box->mlx.mlx_win, box->point->x+WIDTH/4, y1+HEIGHT/4, 0XFF0000);
		box->point->x++;
	}
	while(box->point->y < y2)
	{
		if (box->point->y/50 < box->nb_line)
			mlx_pixel_put(box->mlx.mlx_conect, box->mlx.mlx_win, x1+WIDTH/4, box->point->y+HEIGHT/4, 0X04FFFF);
		box->point->y++;
	}
}

void	ft_mlx_and_draw(t_fdf	*box)
{
	box->mlx.mlx_conect = mlx_init();
	box->mlx.mlx_win = mlx_new_window(box->mlx.mlx_conect, WIDTH, HEIGHT, box->maps_name);
	box->mlx.mlx_img = mlx_new_image(box->mlx.mlx_conect, WIDTH, HEIGHT);
	while (box->point && box->point->next)
	{
		ft_draw_lines(box->point->x*50, box->point->next->x*50, box->point->y*50, box->point->next->y*50, box);
		box->point = box->point->next;
	}
	mlx_loop(box->mlx.mlx_conect);
}
