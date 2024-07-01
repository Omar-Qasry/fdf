# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 01:11:49 by oel-qasr          #+#    #+#              #
#    Updated: 2024/07/01 10:55:12 by oel-qasr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_B = fdf_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = mandatory/fdf.c mandatory/ft_map_error_check.c mandatory/get_next_line_utils.c mandatory/get_next_line.c \
		mandatory/ft_error.c mandatory/ft_utils.c mandatory/ft_parsing.c mandatory/ft_push.c mandatory/ft_split.c \
		mandatory/linked_list.c mandatory/ft_mlx_and_draw.c\

SRCS_B = \

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mandatory/%.o : mandatory/%.c mandatory/fdf.h
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


bonus : $(NAME_B)

$(NAME_B) : $(OBJS_B)
		$(CC) $(OBJS_B) -o fdf_bonus

bonus/%.o : bonus/%.c bonus/fdf_bonus.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(OBJS_B)

fclean: clean
		$(RM) $(NAME)
		$(RM) fdf_bonus

re: fclean all

.PHONY: clean fclean
