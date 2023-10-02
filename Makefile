# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 00:37:15 by lfiorini          #+#    #+#              #
#    Updated: 2023/10/02 22:19:59 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror #-g3 -fsanitize=address
FRAMEWORKS	= -framework Cocoa -framework OpenGL -framework IOKit

# DIRECTORIES #

SRCS_DIR	= sources/
OBJS_DIR	= objects/
INC_DIR		= include/
LIBFT_DIR	= libraries/libft/
MLX_DIR		= libraries/MLX42/

LIB_MLX42	= libraries/MLX42/build/libmlx42.a
LIBFT		= libraries/libft/libft.a
INCLUDE		= -I./ -I./include -I./libraries/libft/include -I./libraries/MLX42 -I./libraries/MLX42/include/MLX42

FILES		= main


SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


# RULES #

all:		libft install_glfw $(NAME)

libft:
			$(MAKE) -C $(LIBFT_DIR)

# libmlx:
# 			$(MAKE) -lglfw -C $(MLX_DIR)

install_glfw:
	@if [ ! -f $(LIB_MLX42) ]; then \
		git submodule update --init --recursive --remote; \
		brew uninstall glfw; \
		cmake -S libraries/MLX42/ -B libraries/MLX42/build -DGLFW_FETCH=1; \
		make -C libraries/MLX42/build; \
		brew install glfw; \
		echo "GLFW installed"; \
	fi

$(NAME):	$(LIBFT) $(LIB_MLX42) $(OBJS)
			$(CC) $(INCLUDE) $(CFLAGS) $(LIBFT) $(LIB_MLX42) $(FRAMEWORKS) -o $(NAME) $(OBJS) 

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@mkdir -p $(OBJS_DIR)
				$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(LIB_MLX42): install_glfw

clean:
			rm -rf $(OBJS_DIR)
			$(MAKE) -C $(LIBFT_DIR) clean
			
fclean:		clean
			rm -f $(NAME)
			rm -f $(LIBFT)

re:			fclean all

.PHONY:		all libft libmlx clean fclean re
