# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 01:11:49 by oel-qasr          #+#    #+#              #
#    Updated: 2024/07/30 10:35:34 by oel-qasr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_B = fdf_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/usr/local/lib/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRCS = mandatory/fdf.c mandatory/ft_map_error_check.c mandatory/get_next_line_utils.c mandatory/get_next_line.c \
		mandatory/ft_error.c mandatory/ft_utils.c mandatory/ft_parsing.c mandatory/ft_push.c mandatory/ft_split.c \
		mandatory/linked_list.c mandatory/ft_mlx_and_draw.c mandatory/ft_drawing_algo.c mandatory/ft_colore.c \
		mandatory/number_utile.c \

SRCS_B = bonus/davinci_bonus.c bonus/fdf_bonus.c bonus/ft_change_point.c bonus/ft_colore_bonus.c \
		bonus/ft_error_bonus.c bonus/ft_hooks_bonus.c bonus/ft_iso_pixel.c bonus/ft_map_error_check_bonus.c\
		bonus/ft_mlx_and_draw_bonus.c bonus/ft_parsing_bonus.c bonus/ft_push_bonus.c bonus/ft_scale_bonus.c\
		bonus/ft_split_bonus.c bonus/ft_translate_bonus.c bonus/ft_utils_bonus.c bonus/ft_zoom_bonus.c\
		bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/linked_list_bonus.c bonus/nb_func_bonus.c\
		bonus/number_utile_bonus.c bonus/Vincent_van_Gogh_bonus.c\

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

mandatory/%.o : mandatory/%.c mandatory/fdf.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B)
		$(CC) $(OBJS_B) $(MLX_FLAGS) -o $(NAME_B)

bonus/%.o : bonus/%.c bonus/fdf_bonus.h
		$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
		$(RM) $(OBJS) $(OBJS_B)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(NAME_B)

re: fclean all

.PHONY: clean fclean
