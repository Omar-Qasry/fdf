/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:35:21 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/31 12:25:58 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	iso(t_point *point)
{
	t_iso	iso;

	iso.previous_x = point->x;
	iso.previous_y = point->y;
	iso.previous_z = point->z;
	point->x = (iso.previous_x - iso.previous_y) * cos(0.523599);
	point->y = (iso.previous_x + iso.previous_y)
		* sin(0.523599) - iso.previous_z;
}

void	iso_d(t_point *point)
{
	t_iso	iso;

	iso.previous_x = point->x_d;
	iso.previous_y = point->y_d;
	iso.previous_z = point->z;
	point->x_d = (iso.previous_x - iso.previous_y) * cos(0.523599);
	point->y_d = (iso.previous_x + iso.previous_y)
		* sin(0.523599) - iso.previous_z;
}

void	my_pixel_put(int x, int y, int color, t_fdf *box)
{
	char	*dst;

	if ((0 <= x && x < WIDTH) && (0 <= y && y < HEIGHT))
	{
		x *= (box->img.bits_per_pixel / 8);
		y *= box->img.win_lenth;
		dst = box->img.mlx_data + x + y;
		*(unsigned int *) dst = color;
	}
}
