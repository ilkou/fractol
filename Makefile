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
SRCS = disp.c ft_calcul.c ft_events.c ft_julia.c ft_monsieur.c ft_tricorne.c
SRCS += ft_burningship.c ft_draw.c ft_init.c ft_mandelbrot.c ft_negatibrot.c main.c

SRC = $(SRCS:%=./srcs/%)
OBJ = $(SRCS:.c=.o)

ifeq ($(shell uname), Darwin)
$(info MacOs detected)
MLX = -lmlx -framework OpenGL -framework AppKit
else
$(info $(shell uname) detected)
MLX = -lm -lmlx -lXext -lX11
endif

FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/ -lft
THREAD = -lpthread
MYLIBS = $(MLX) -L $(LIBFT) $(THREAD)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $^ $(MYLIBS)

%.o: ./srcs/%.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
