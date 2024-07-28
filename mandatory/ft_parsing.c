/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:58:44 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/27 09:27:09 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

unsigned int	color_gradient(t_fdf *box)
{
	static float	k;
	static int		x;
	static int		y;
	unsigned int	color;

	color = get_cr(0x91F1EF, 0xFFD5E0, speed_color(x, y) + (k / 4));
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

void	norm2(char **splite_rows, t_fdf *box, char **line, int k)
{
	char	*color;
	int		i;

	i = 0;
	while (splite_rows[i])
	{
		color = find_color(splite_rows[i]);
		if (color)
			box->var.color = ft_atoi_base(color);
		else
			box->var.color = color_gradient(box);
		free(color);
		box->var.z = ft_atoi(splite_rows[i]);
		ft_push(box);
		box->var.x++;
		free(*line);
		*line = NULL;
		i++;
		k += 0.1;
	}
}

void	ft_parsing(t_fdf *box)
{
	char	*line;
	char	**splite_rows;
	float	k;

	k = 0;
	box->maps_fd = open(box->maps_name, O_RDONLY);
	if (box->maps_fd == -1)
		ft_error("no such file");
	line = get_next_line(box->maps_fd);
	while (line)
	{
		splite_rows = ft_split(line, ' ');
		box->var.x = 0;
		norm2(splite_rows, box, &line, k);
		free(line);
		is_free(splite_rows);
		line = get_next_line(box->maps_fd);
		box->var.y++;
	}
	free(line);
}
