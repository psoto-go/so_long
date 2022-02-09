# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 16:57:12 by psoto-go          #+#    #+#              #
#    Updated: 2022/02/09 12:38:36 by psoto-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/main.c srcs/control_map.c srcs/errors.c \
					srcs/print_map.c srcs/control_term.c srcs/init_mlx.c \
					srcs/move_player.c srcs/exit_mlx.c srcs/keys.c \
					srcs/control_map2.c srcs/move_enemy.c srcs/load_map.c \
					srcs/move_position.c srcs/control_map3.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make
LIBFT			= libft
NAME			= so_long
MLX				= mlx

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) all -C $(MLX)
				$(MAKE) all -C $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
				$(MAKE) clean -C $(MLX)
				$(MAKE) clean -C $(LIBFT)
				$(RM) $(OBJS)


fclean:			clean
				$(MAKE) fclean -C $(LIBFT)
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re