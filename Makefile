NAME		=	cub3D

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -MMD #-g3 -fsanitize=address
MLXFLAGS	=	-lglfw -framework Cocoa -framework OpenGL -framework IOKit

# DIRECTORIES #

INCS_DIR	=	include
LIBS_DIR	=	lib
SRCS_DIR	=	src
SUBDIRS		=	game parser utils
BUILD_DIR	=	build

LIBFT_DIR	=	$(LIBS_DIR)/libft
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX_DIR		=	$(LIBS_DIR)/MLX42
MLX_BUILD	=	$(MLX_DIR)/build
MLX42		=	$(MLX_BUILD)/libmlx42.a

INCS		=	-I./$(INCS_DIR) -I./$(LIBFT_DIR)/include -I./$(MLX_DIR) \
				-I./$(MLX_DIR)/include/MLX42
SRCS		=	$(SRCS_DIR)/main.c \
				$(foreach dir, $(SUBDIRS), $(wildcard $(SRCS_DIR)/$(dir)/*.c))
OBJS		=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS		=	$(OBJS:.o=.d)

# RULES #

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	$(CC) $(INCS) $(CFLAGS) $(LIBFT) $(MLX42) $(MLXFLAGS) -o $@ $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX42):
	@if [ ! -f $(MLX42) ]; then \
		git submodule update --init --recursive --remote; \
		brew install glfw \
		cmake -S $(MLX_DIR)/ -B $(MLX_DIR)/build -DGLFW_FETCH=1; \
		make -C $(MLX_DIR)/build; \
	fi

-include $(DEPS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCS) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re