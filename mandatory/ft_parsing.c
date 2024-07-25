/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:58:44 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/25 09:41:04 by oel-qasr         ###   ########.fr       */
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
void	help_color(int c1, int c2, t_fdf *box)
{
	box->color.color1 = c1;
	box->color.color2 = c2;
}
void	ft_change_color(t_fdf	*box)
{
	if (box->color.x == 'm')
		help_color(ft_atoi_base("91F1EF"), ft_atoi_base("FFD5E0"), box);
	else if (box->color.x == 0)
		help_color (ft_atoi_base("DB2763"), ft_atoi_base("B0DB43"), box);
	else if (box->color.x == 1)
		help_color (ft_atoi_base("E43D00"), ft_atoi_base("FFE900"), box);
	else if (box->color.x == 2)
		help_color (ft_atoi_base("E4F3E3"), ft_atoi_base("5CA9E9"), box);
	else if (box->color.x == 3)
		help_color (ft_atoi_base("BCE7FC"), ft_atoi_base("C491B1"), box);
	else if (box->color.x == 4)
		help_color (ft_atoi_base("DAFF7D"), ft_atoi_base("B2EE9B"), box);
	else if (box->color.x == 5)
		help_color (ft_atoi_base("F7DBA7"), ft_atoi_base("F0AB86"), box);
	else if (box->color.x == 6)
		help_color (ft_atoi_base("264653"), ft_atoi_base("2A9D8F"), box);
	else if (box->color.x == 7)
		help_color (ft_atoi_base("505250"), ft_atoi_base("CBD3C1"), box);
	else if (box->color.x == 8)
		help_color (ft_atoi_base("FCFB62"), ft_atoi_base("91F9E5"), box);
	else if (box->color.x == 9)
		help_color (ft_atoi_base("00C1D0"), ft_atoi_base("0A0F44"), box);
}

void	ft_parsing(t_fdf *box)
{
	char	*line;
	char	**splite_rows;
	int		i;
	char	*color;
	float	k;

	i = 0;
	k = 0;
	box->maps_fd = open(box->maps_name, O_RDONLY);
	if (box->maps_fd == -1)
		ft_error("no such file");
	line = get_next_line(box->maps_fd);
	while (line)
	{
		splite_rows = ft_split(line, ' ');
		box->var.x = 0;
		i = 0;
		while (splite_rows[i])
		{
			color = find_color(splite_rows[i]);
			if (color)
				box->var.color = ft_atoi_base(color);
			else
			{
				box->color.x = 'm';
				ft_change_color(box);
				box->var.color = get_cr(box->color.color1, box->color.color2, speed_color(box->var.x, box->var.y) + (k/4));
			}
			free(color);
			box->var.z = ft_atoi(splite_rows[i]);
			ft_push(box);
			box->var.x++;
			free(line);
			line = NULL;
			i++;
			k += 0.1;
		}
		free(line);
		is_free(splite_rows);
		line = get_next_line(box->maps_fd);
		box->var.y++;
	}
	free(line);
}
