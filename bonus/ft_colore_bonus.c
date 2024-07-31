/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:40:03 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/31 12:25:01 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	color_back(t_fdf *box, int x)
{
	int				i;
	int				j;
	unsigned int	c1;
	unsigned int	c2;

	i = 0;
	j = 0;
	c1 = 0x000000;
	c2 = 0xc0c0c0;
	if (x == 1)
		c2 *= ft_random();
	while (i <= HEIGHT)
	{
		j = 0;
		while (j <= WIDTH)
		{
			my_pixel_put((int)j, (int)i,
				get_cr(c1, c2, speed_color(j, i)), box);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(box->mlx_conect,
		box->mlx_win, box->img.mlx_img, 0, 0);
}

char	*find_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (ft_substr(str, i + 3, ft_strlen(str + i)));
		i++;
	}
	return (0);
}

unsigned int	color_gradient(t_fdf *box, int i)
{
	static float	k;
	static int		x;
	static int		y;
	unsigned int	color;

	ft_change_color(box, i);
	color = get_cr(box->color.color1,
			box->color.color2, speed_color(x, y) + (k / 4));
	if (x == (box->line_length - 1))
	{
		x = 0;
		y += 1;
	}
	else
		x += 1;
	k += 0.1;
	return (color);
}
