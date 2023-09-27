# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 00:37:15 by lfiorini          #+#    #+#              #
#    Updated: 2023/09/21 18:10:50 by lfiorini         ###   ########.fr        #
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

LIB_MLX42	= $(MLX_DIR)build/libmlx42.a
LIBFT		= $(LIBFT_DIR)libft.a
INCLUDE		= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

FILES		= main


SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


# RULES #

all:		libft libmlx $(NAME)

libft:
			$(MAKE) -C $(LIBFT_DIR)

libmlx:
			$(MAKE) -lglfw -C $(MLX_DIR)
			

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Lmlx -lmlx -Llibft -lft $(FRAMEWORKS)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@mkdir -p $(OBJS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
				
clean:
			rm -rf $(OBJS_DIR)
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(MLX_DIR) clean
			
fclean:		clean
			rm -f $(NAME)
			rm -f $(LIBFT)
			rm -f $(LIB_MLX42)

re:			fclean all

.PHONY:		all libft libmlx clean fclean re
