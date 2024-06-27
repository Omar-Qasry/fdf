/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 05:26:49 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/27 15:14:22 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_error_check(char *av, t_fdf *box)
{

	char *line;

	line = "\0";

	box->maps_name = open(av, O_RDONLY);
	if (box->maps_name == -1)
		ft_error("no such file");
	line = get_next_line(box->maps_name);
	if (!line)
		ft_error("No data found.\n");
	box->line_length = ft_count_words(line, ' ');
	free(line);
	line = NULL;
	while (line)
	{
		line = get_next_line(box->maps_name);
		if (ft_count_words(line, ' ') != box->line_length)
			ft_error("Found wrong line length. Exiting\n");
		free(line);
	}
	close(box->maps_name);
}
