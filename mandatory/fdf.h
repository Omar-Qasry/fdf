/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:15:09 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/23 06:37:04 by oel-qasr         ###   ########.fr       */
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
# include "/usr/local/include/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080
# define RED_X 17
# define ESC 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2123500000
# endif

typedef struct s_iso
{
	int	previous_x;
	int	previous_y;
	int	previous_z;
	int	previous_x2;
	int	previous_y2;
	int	previous_z2;
}	t_iso;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*next;
}	t_point;


/*


*/

typedef struct s_draw
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
	int	e2;
}	t_draw;
typedef struct s_var
{
	int	x;
	int	x2;
	int	y;
	int	y2;
	int	z;
	int	z2;
	int	color;
}	t_var;

typedef struct s_mlx
{
	void	*mlx_img;
	char	*mlx_data;
	int		bits_per_pixel;
	int		win_lenth;
	int		endian;
}	t_mlx;

typedef struct s_fdf
{
	void			*mlx_win;
	void			*mlx_conect;
	char			*maps_name;
	int				line_length;
	int				nb_line;
	int				maps_fd;
	t_mlx			img;
	struct s_var	var;
	struct s_point	*point;
	struct s_draw	draw;
}	t_fdf;

// linked list
t_point	*ft_lstnew(t_var *var);
void	ft_lstadd_back(t_point **lst, t_point *newx);
t_point	*ft_lstlast(t_point *lst);
int		ft_lstsize(t_point *lst);
void	ft_lstclear(t_fdf *lst);

// parsing functions
void	ft_map_error_check(t_fdf *box);
void	ft_parsing(t_fdf *box);
void	ft_push(t_fdf	*box);
int		ft_count_words(const char *str);

//util functions
int		ft_atoi_base(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
long	ft_atoi(char *str);

// error function
void	ft_error(char *str);
void	*is_free(char **return_arr);
// mlx and draw functions
void	ft_mlx_and_draw(t_fdf	*box);
void	ft_draw_line(t_fdf *box);
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
