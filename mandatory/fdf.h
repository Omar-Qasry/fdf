/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:15:09 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/29 18:34:55 by oel-qasr         ###   ########.fr       */
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

typedef struct s_point
{
	int 			x;
	int 			y;
	int				z;
	struct s_point *next;
}t_point ;

typedef struct s_fdf
{
	void			*img;
	void			*mlx;
	void			*mlx_win;
	char			*maps_name;
	int				line_length;
	int				nb_line;
	int				maps_fd;
}t_fdf;

// linked list
t_point	*ft_lstnew(int x, int y, int z);
void	ft_lstadd_back(t_point **lst, t_point *newx);
t_point	*ft_lstlast(t_point *lst);
int		ft_lstsize(t_point *lst);
// void	ft_lstclear(t_fdf **lst);

void	ft_push(t_point **point, int row, int colone, int z);
void	*ft_calloc(size_t count, size_t size);
int		ft_count_words(const char *str);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
long	ft_atoi(char *str);

// error function
void	ft_error(char *str);
void	*is_free(char **return_arr);

void	ft_map_error_check(t_fdf *box);
void	ft_parsing(t_fdf *box, t_point **point);

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

