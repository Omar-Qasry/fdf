/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:09:18 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/29 18:50:38 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_fdf	*box;
		t_point *point;

		box = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
		// point = (t_point *)ft_calloc(1, sizeof(t_point));
		point = NULL;
		box->maps_name = av[1];
		ft_map_error_check(box);
		ft_parsing(box, &point);
		int i = 0;
		while (point)
		{
			printf();
		}
		// printf("%d %d\n", box->nb_line, box->line_length);
		// ft_mlx_and_draw(&box);
		//a free function needed
		free(box);
	}
	else
		ft_error("wrong argument");
	return (0);
}
