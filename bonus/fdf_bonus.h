/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:15:09 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/29 18:29:11 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

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
# define paint_all 35 // p
# define paint_ba 11 // B
# define paint_z 15 // R
# define paint_low_z 5 // G
# define resset 7 // x
# define up 126
# define down 125
# define Left 123
# define right 124
# define minus 78 // -
# define plus 69 // +
# define prajection 8 // C
# define BUFFER_SIZE 21474836

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
	int				x_d;
	int				x_c;
	int				x_z;
	int				y;
	int				y_d;
	int				y_c;
	int				y_z;
	int				z;
	int				z_d;
	int				z_z;
	int				color;
	struct s_point	*next;
}	t_point;

typedef struct s_color
{
	unsigned int	color1;
	unsigned int	color2;
	int				x;
}	t_color;

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
	float			zoom_s;
	struct s_var	var;
	struct s_point	*point;
	struct s_draw	draw;
	struct s_color	color;
}	t_fdf;

// linked list
t_point			*ft_lstnew(t_var *var);
void			ft_lstadd_back(t_point **lst, t_point *newx);
t_point			*ft_lstlast(t_point *lst);
int				ft_lstsize(t_point *lst);
void			ft_lstclear(t_fdf *lst);
t_point			*ft_point_copy(t_point *lst);

// parsing functions
void			ft_map_error_check(t_fdf *box);
void			ft_parsing(t_fdf *box);
void			ft_push(t_fdf	*box);
int				ft_count_words(const char *str);
//util functions
int				ft_atoi_base(const char *str);
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
long			ft_atoi(char *str);
int				min(int a, int b);
int				ft_random();
// error function
void			ft_error(char *str);
void			*is_free(char **return_arr);
int				ft_destory(t_fdf *box);
// mlx and draw functions
void			ft_mlx_and_draw(t_fdf	*box);
void			ft_draw_line(t_point x1, t_point x2, t_fdf *box);
void			my_pixel_put(int x, int y, int color, t_fdf *box);
void			ft_prepar_point(t_point *point, t_fdf *box, float z);
void			davinchi(t_fdf	*box);
void			scale_list(t_fdf *box);
void			translate(t_fdf	*box, int x);
void			iso(t_point *point);
void			zoom(t_point *point, t_fdf *box,int z);
void			ft_conic(t_fdf *box);
void			ft_zoum_min(t_fdf *box);
void			ft_zoum_up(t_fdf *box);
void			make_conic(t_fdf *box);
void			go_to_conic(t_fdf *box);
void			ft_prepar_point_c(t_point *point, t_fdf *box, float z);
void			ft_prepar_point_d(t_point *point, t_fdf *box, float z);
void			go_to_zoom(t_fdf *box);
// colore functions
unsigned int	get_cr(unsigned int color1, unsigned int color2, float t);
void			color_back(t_fdf *box, int x);
float			speed_color(int x, int y);
int				ft_change_color(t_fdf *box, int x);
unsigned int	color_gradient(t_fdf *box, int i);
char			*find_color(char *str);
void			ft_new_color(t_fdf *box);
void			ft_paint_z(t_fdf *box);
void			ft_paint_low_z(t_fdf *box);
void			ft_paint_all(t_fdf *box);
void			ft_draw_y_lines(t_fdf box,t_point *point, int x, int p);
void			ft_draw_x_lines(t_fdf box,t_point *point, int x, int p);
void			go_back(t_fdf *box);
//get_next_line function
char			*get_next_line(int fd);
size_t			ft_strlen(char const *str);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(char *str, int c);
#endif
