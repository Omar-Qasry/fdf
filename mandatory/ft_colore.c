/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:40:03 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/25 11:51:11 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_cr(unsigned int color1, unsigned int color2, float t)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (((color1 >> 16) & 0xFF) * (1 - t) + ((color2 >> 16) & 0xFF) * t);
	g = (((color1 >> 8) & 0xFF) * (1 - t) + ((color2 >> 8) & 0xFF) * t);
	b = (((color1) & 0xFF) * (1 - t) + ((color2) & 0xFF) * t);
	return ((r << 16 | g << 8 | b) & 0xFFFFFF);
}

float	speed_color(int x, int y)
{
	return ((float)(x * HEIGHT + y * 380) / (WIDTH * HEIGHT * 1.5));
}

void	color_back(t_fdf *box)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= HEIGHT)
	{
		j = 0;
		while (j <= WIDTH)
		{
			my_pixel_put(j, i,
				get_cr(0x000000, 0xc0c0c0, speed_color(j, i)), box);
			j++;
		}
		i++;
	}
}
