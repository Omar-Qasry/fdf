/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:09:18 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/27 17:08:48 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
// void	f()
// {
	// system("leaks fdf");
// }
	// atexit(f);
int	main(int ac, char **av)
{
	t_fdf	*box;

	if(ac != 2)
		ft_error("wrong argument");
	box = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	box->maps_name = av[1];
	ft_map_error_check(box);
	ft_parsing(box);
	ft_mlx_and_draw(box);
	return (0);
}
