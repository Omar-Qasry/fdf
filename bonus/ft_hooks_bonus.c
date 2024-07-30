/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:49:03 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 09:00:03 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_paint_low_z(t_fdf *box)
{
	static int	i;

	if (i >= 8)
		i = 0;
	mlx_clear_window(box->mlx_conect, box->mlx_win);
	color_back(box, 0);
	ft_draw_x_lines(*box, box->point, i, -2);
	ft_draw_y_lines(*box, box->point, i, -2);
}

void	ft_paint_z(t_fdf *box)
{
	static int	i;

	if (i >= 8)
		i = 0;
	mlx_clear_window(box->mlx_conect, box->mlx_win);
	color_back(box, 0);
	ft_draw_x_lines(*box, box->point, i, -3);
	ft_draw_y_lines(*box, box->point, i, -3);
}

void	ft_new_color(t_fdf *box)
{
	static int	i;

	if (i >= 8)
		i = 0;
	mlx_clear_window(box->mlx_conect, box->mlx_win);
	color_back(box, 0);
	ft_draw_x_lines(*box, box->point, i, 0);
	ft_draw_y_lines(*box, box->point, i, 0);
	i++;
}

void	ft_paint_all(t_fdf *box)
{
	mlx_clear_window(box->mlx_conect, box->mlx_win);
	color_back(box, 1);
	ft_draw_x_lines(*box, box->point, -1, -1);
	ft_draw_y_lines(*box, box->point, -1, -1);
}

void	make_conic(t_fdf *box)
{
	go_to_conic(box);
	mlx_clear_window(box->mlx_conect, box->mlx_win);
	color_back(box, 0);
	ft_draw_x_lines(*box, box->point, -1, -1);
	ft_draw_y_lines(*box, box->point, -1, -1);
}
