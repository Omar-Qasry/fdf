/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_davinci_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:52:51 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 08:59:47 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	help_color(unsigned int c1, unsigned int c2, t_fdf *box)
{
	box->color.color1 = c1;
	box->color.color2 = c2;
}

int	ft_change_color(t_fdf	*box, int x)
{
	if (x == -1)
		help_color(0x91F1EF, 0xFFD5E0, box);
	else if (x == 0)
		help_color (0xE43D00, 0xFFE900, box);
	else if (x == 1)
		help_color (0xE4F3E3, 0x5CA9E9, box);
	else if (x == 2)
		help_color (0xBCE7FC, 0xC491B1, box);
	else if (x == 3)
		help_color (0xDAFF7D, 0xB2EE9B, box);
	else if (x == 4)
		help_color (0xF7DBA7, 0xF0AB86, box);
	else if (x == 5)
		help_color (0x264653, 0x2A9D8F, box);
	else if (x == 6)
		help_color (0x505250, 0xCBD3C1, box);
	else if (x == 7)
		help_color (0xFCFB62, 0x91F9E5, box);
	else if (x == 8)
		help_color (0x000000, 0xffffff, box);
	return (0);
}

void	davinci(t_fdf *box)
{
	mlx_clear_window(box->mlx_conect, box->mlx_win);
	color_back(box, 0);
	ft_draw_x_lines(*box, box->point, -1, -1);
	ft_draw_y_lines(*box, box->point, -1, -1);
}
