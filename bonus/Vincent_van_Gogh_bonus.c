/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vincent_van_Gogh_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:50:20 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 11:35:04 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

unsigned int	determine_color_x(t_fdf box, t_point *point, int x, int p)
{
	unsigned int	color;

	color = 0;
	if (p == -3)
	{
		if (point->z > 5)
			color = color_gradient(&box, x);
		else
			color = point->color;
	}
	else if (p == -2)
	{
		if (point->z < 5)
			color = color_gradient(&box, x);
		else
			color = point->color;
	}
	else if (p == 0)
		color = color_gradient(&box, x);
	else if (p == -1)
		color = point->color;
	return (color);
}

void	ft_draw_x_lines(t_fdf box, t_point *point, int x, int p)
{
	int		j;
	t_point	*tmp;

	j = 0;
	tmp = point;
	while (tmp && tmp->next)
	{
		if (j >= (box.line_length - 1))
		{
			tmp = tmp->next;
			j = 0;
			continue ;
		}
		j++;
		box.var.color = determine_color_x(box, tmp, x, p);
		ft_draw_line(*tmp, *tmp->next, &box);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(box.mlx_conect, box.mlx_win, box.img.mlx_img, 0, 0);
}

unsigned int	determine_color_y(t_fdf box, t_point *point, int x, int p)
{
	unsigned int	color;

	color = 0;
	if (p == -3)
	{
		if (point->z > 5)
			color = color_gradient(&box, x);
		else
			color = point->color;
	}
	else if (p == -2)
	{
		if (point->z < 5)
			color = color_gradient(&box, x);
		else
			color = point->color;
	}
	else if (p == 0)
		color = color_gradient(&box, x);
	else if (p == -1)
		color = point->color;
	return (color);
}

int	skip_initial_points(t_point **point, int count)
{
	int	i;

	i = 0;
	while (i < count && *point)
	{
		*point = (*point)->next;
		i++;
	}
	return (i);
}

void	ft_draw_y_lines(t_fdf box, t_point *point, int x, int p)
{
	t_point	*tmp;
	int		i;

	tmp = point;
	i = 0;
	i = skip_initial_points(&tmp, box.line_length);
	while (tmp)
	{
		box.var.color = determine_color_y(box, point, x, p);
		ft_draw_line(*point, *tmp, &box);
		tmp = tmp->next;
		point = point->next;
	}
	mlx_put_image_to_window(box.mlx_conect, box.mlx_win, box.img.mlx_img, 0, 0);
}
