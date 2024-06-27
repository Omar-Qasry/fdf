/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:15:09 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/27 15:03:32 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <mlx.h>

# define WIDTH 500
# define HEIGHT 500

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct	s_fdf
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	int		line_length;
	int		maps_name;
}t_fdf;

void	*ft_calloc(size_t count, size_t size);
int		ft_count_words(const char *str, char d);
void	ft_bzero(void *s, size_t n);
void	ft_error(char *str);

void	ft_map_error_check(char *av, t_fdf *box);

//get_next_line function
char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int c);
#endif

