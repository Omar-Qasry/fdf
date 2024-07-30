/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:58:44 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 10:38:54 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	process_line(t_fdf *box, char *line)
{
	char	**splite_rows;
	int		i;
	char	*color;

	splite_rows = ft_split(line, ' ');
	box->var.x = 0;
	i = 0;
	while (splite_rows[i])
	{
		color = find_color(splite_rows[i]);
		if (color)
			box->var.color = ft_atoi_base(color);
		else
			box->var.color = color_gradient(box, -1);
		free(color);
		box->var.z = ft_atoi(splite_rows[i]);
		ft_push(box);
		box->var.x++;
		i++;
	}
	is_free(splite_rows);
}

void	ft_parsing(t_fdf *box)
{
	char	*line;

	box->maps_fd = open(box->maps_name, O_RDONLY);
	if (box->maps_fd == -1)
		ft_error("no such file");
	line = get_next_line(box->maps_fd);
	while (line)
	{
		process_line(box, line);
		free(line);
		line = get_next_line(box->maps_fd);
		box->var.y++;
	}
	free(line);
}
