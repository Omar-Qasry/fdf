/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:09:18 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/27 15:03:46 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_fdf	*box;

		box = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
		ft_map_error_check(av[1], box);

		// ft_parsing(&box);
		// ft_mlx_and_draw(&box);
		//a free function needed
		free(box);
	}
	else
		ft_error("wrong argument");
	return (0);
}
