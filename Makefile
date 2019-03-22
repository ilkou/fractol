# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oouklich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 14:32:27 by oouklich          #+#    #+#              #
#    Updated: 2019/03/22 21:29:38 by oouklich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = ./srcs/*.c
INCLUDES = ./minilibx_macos
FLAGS = -Wall -Wextra -Werror
MLX = ./minilibx -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/ -lft
THREAD = . -lpthread
all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(INCLUDES) -L $(MLX) -L $(LIBFT) -L $(THREAD)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
