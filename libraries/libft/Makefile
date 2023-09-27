# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 03:23:39 by lfiorini          #+#    #+#              #
#    Updated: 2023/04/24 04:45:19 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

LIBFT_F		:= ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_itoa \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_split \
			ft_strchr \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtrim \
			ft_substr \
			ft_tolower \
			ft_toupper \
			ft_lstadd_back \
			ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstlast \
			ft_lstmap \
			ft_lstnew \
			ft_lstsize
GNL_F		:= get_next_line \
			get_next_line_utils
PRINTF_F	:= ft_printf \
			ft_printf_utils \
			print_chars \
			print_digits \
			ft_parser \
			ft_converter \
			ft_printf_bonus

SRCS 		= $(addprefix ${LIBFT_DIR}, $(addsuffix .c, $(LIBFT_F))) \
			$(addprefix ${GNL_DIR}, $(addsuffix .c, $(GNL_F))) \
			$(addprefix ${PRINTF_DIR}, $(addsuffix .c, $(PRINTF_F)))
OBJS		= $(addprefix ${OBJS_DIR}, $(addsuffix .o, $(LIBFT_F))) \
			$(addprefix ${OBJS_DIR}, $(addsuffix .o, $(GNL_F))) \
			$(addprefix ${OBJS_DIR}, $(addsuffix .o, $(PRINTF_F)))
DEPS		= $(addprefix ${OBJS_DIR}, $(addsuffix .d, $(LIBFT_F))) \
			$(addprefix ${OBJS_DIR}, $(addsuffix .d, $(GNL_F))) \
			$(addprefix ${OBJS_DIR}, $(addsuffix .d, $(PRINTF_F)))

# DIRECTORIES
LIBFT_DIR	= libft/
GNL_DIR		= get_next_line/
PRINTF_DIR	= ft_printf/
OBJS_DIR	= objects/


# FLAGS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
INCLUDE		+= -I./include


# RULES

all:		$(NAME)

$(NAME): 	$(OBJS)
			@echo "libft compiled"
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)		

${OBJS_DIR}%.o:  ${LIBFT_DIR}%.c 
			@mkdir -p $(dir $@)
			$(CC) -c $(CFLAGS) $(INCLUDE) -MMD -MP  $< -o $@
${OBJS_DIR}%.o:  ${GNL_DIR}%.c
			@mkdir -p $(dir $@)
			$(CC) -c $(CFLAGS) $(INCLUDE) -MMD -MP $< -o $@
${OBJS_DIR}%.o:  ${PRINTF_DIR}%.c 
			@mkdir -p $(dir $@)
			$(CC) -c $(CFLAGS) $(INCLUDE) -MMD -MP $< -o $@

clean:
			${RM} $(OBJS_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
