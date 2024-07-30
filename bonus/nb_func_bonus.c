/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_func_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:51:18 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/30 08:51:43 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	random_help(int seed)
{
	static int	r;

	r += 1 + (int)(&seed);
	r = (r << (1 + (seed & 32)));
	return (r);
}

int	ft_random(void)
{
	return (random_help(0) % 1000);
}
