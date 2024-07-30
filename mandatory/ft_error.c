/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 06:35:21 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/29 21:36:52 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

void	ft_error(char *str)
{
	ft_putstr_fd(str);
	exit(EXIT_FAILURE);
}

int	ft_destory(t_fdf *box)
{
	mlx_clear_window(box->mlx_conect, box->mlx_win);
	mlx_destroy_image(box->mlx_conect, box->img.mlx_img);
	mlx_destroy_window(box->mlx_conect, box->mlx_win);
	ft_lstclear(box->point);
	free(box);
	exit(EXIT_SUCCESS);
	return (0);
}
