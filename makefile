# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 14:58:58 by wchen             #+#    #+#              #
#    Updated: 2023/10/29 19:54:45 by kitsuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

UNAME			=	$(shell uname)
# CC and CFLAGS
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP \

#IFLAGS
INCLUDES_DIR	=	./includes
IFLAGS			=	-I$(INCLUDES_DIR) -I$(LIBFT_INC) -I$(MLX_INC)

##libft
LIBFT_DIR		=	./libft
LIBFT_INC		=	./libft/includes
LIBFT_LIB		=	-L $(LIBFT_DIR) -lft

##minilibx
MLX_DIR			=	./minilibx-linux
MLX_INC			=	$(MLX_DIR)
ifeq ($(UNAME), Darwin)
MLX_LIB			=	-L $(MLX_DIR) -lmlx_$(UNAME) -L/usr/X11R6/lib -lX11 -lXext -lm	\
						 -framework OpenGL -framework AppKit
else
MLX_LIB			=	-L $(MLX_DIR) -lmlx_$(UNAME) -L/usr/X11R6/lib -lX11 -lXext -lm
endif

#cub3d
SRC_DIR			=	./srcs
SRC				=	ft_error.c				\
					main.c					\
					test.c					\
					validation.c			\
					fd_check.c				\
					line_check.c			\
					line_judge.c			\
					create_map_array.c		\
					identifier_judge.c		\
					add_img_lst.c			\
					add_color_lst.c			\
					wall_check.c			\
					mlx_initial.c			\
					key_hook.c				\
					destory_hook.c			\
					free_all.c				\
					start.c


SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))

# SRC				=	$(shell find $(SRC_DIR) -name '*.c')

OBJ_DIR			=	./objs
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

DEPS			=	$(SRC:%.c=%.d)

all: libft_make mlx_make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $$(dirname $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

libft_make:
	make -C $(LIBFT_DIR)

mlx_make:
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f ${MAIN_OBJ}
	rm -rf ${OBJ_DIR}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

re: fclean all

norm:
	@norminette -v
	norminette $(LIBFT_DIR) $(INCLUDES_DIR) $(SRC_DIR)

.PHONY: all clean fclean re norm

-include	$(DEPS)