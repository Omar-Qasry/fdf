/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:58:44 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/29 18:41:30 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parsing(t_fdf *box, t_point **point)
{
	char	*line;
	char	**splite_rows;
	int	x;
	int	y;
	int	z;
	int	i;

	x = 0;
	y = 0;
	z = 0;
	i = 0;
	box->maps_fd = open(box->maps_name, O_RDONLY);
	if (box->maps_fd == -1)
			ft_error("no such file");
	line = get_next_line(box->maps_fd);
	while (line)
	{
		printf("%d\n", y);
		splite_rows = ft_split(line, ' ');
		while (splite_rows[i])
		{
			z = ft_atoi(splite_rows[i]);
			ft_push(point, x, y, z);
			x++;
			// free(line);
			line = NULL;
			i++;
		}
		line = get_next_line(box->maps_fd);
		// is_free(splite_rows);
		y++;
	}
	// is_free(splite_rows);
	// free(line);
}
