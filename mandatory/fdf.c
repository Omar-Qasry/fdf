/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:09:18 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/01 11:11:58 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_fdf	*box;
		t_point	*point;
		t_mlx	mlx;

		box = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
		// point = (t_point *)ft_calloc(1, sizeof(t_point));
		point = NULL;
		box->maps_name = av[1];
		ft_map_error_check(box);
		ft_parsing(box, &point);
		ft_mlx_and_draw(box, &mlx);
		// int i = 0;
		// while (point)
		// {
		// 	printf("x->  %i   y->  %i   z->  %i   color->   %d\n", point->x, point->y, point->z, point->color);
		// 	point = point->next;
		// }
		// printf("%d %d\n", box->nb_line, box->line_length);
		//a free function needed
		free(box);
	}
	else
		ft_error("wrong argument");
	return (0);
}
