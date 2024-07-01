/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:58:44 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/30 21:52:06 by oel-qasr         ###   ########.fr       */
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
void	ft_parsing(t_fdf *box, t_point **point)
{
	char	*line;
	char	**splite_rows;
	t_var	var;
	int		i;

	i = 0;
	box->maps_fd = open(box->maps_name, O_RDONLY);
	if (box->maps_fd == -1)
			ft_error("no such file");
	line = get_next_line(box->maps_fd);
	while (line)
	{
		splite_rows = ft_split(line, ' ');
		var.x = 0;
		i = 0;
		while (splite_rows[i])
		{
			var.color = ft_atoi_base("04FFFF");
			if (find_color(splite_rows[i]))
				var.color = ft_atoi_base(find_color(splite_rows[i]));
			var.z = ft_atoi(splite_rows[i]);
			ft_push(point, &var);
			var.x++;
			line = NULL;
			i++;
		}
		free(line);
		line = get_next_line(box->maps_fd);
		is_free(splite_rows);
		var.y++;
	}
	free(line);
}
