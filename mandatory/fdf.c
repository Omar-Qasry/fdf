/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:09:18 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/06 16:30:46 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_fdf	*box;

		box = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
		box->maps_name = av[1];
		ft_map_error_check(box);
		ft_parsing(box);
		ft_mlx_and_draw(box);
		// int i = 0;
		// while (box->point)
		// {
		// 	printf("x->  %i   y->  %i   z->  %i   color->   %d\n", box->point->x, box->point->y, box->point->z, box->point->color);
		// 	box->point = box->point->next;
		// }
		// printf("%d %d\n", box->nb_line, box->line_length);
		//a free function needed
		exit(EXIT_SUCCESS);
	}
	else
		ft_error("wrong argument");
	return (0);
}
