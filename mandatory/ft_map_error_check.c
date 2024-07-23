/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 05:26:49 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/21 20:45:12 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_error_check(t_fdf *box)
{
	char	*line;

	box->maps_fd = open(box->maps_name, O_RDONLY);
	if (box->maps_fd == -1)
		ft_error("no such file");
	box->nb_line = 0;
	line = get_next_line(box->maps_fd);
	if (!line)
		ft_error("No data found.\n");
	box->line_length = ft_count_words(line);
	box->nb_line++;
	while (line)
	{
		free(line);
		line = get_next_line(box->maps_fd);
		if (!line)
			break ;
		box->nb_line++;
		if (ft_count_words(line) != box->line_length)
			ft_error("Found wrong line length. Exiting\n");
	}
	free(line);
	line = NULL;
	close(box->maps_fd);
}
