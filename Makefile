# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:15:08 by chajjar           #+#    #+#              #
#    Updated: 2023/02/08 12:23:28 by charleshajj      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC =	srcs/main.c srcs/check_map.c \
		srcs/parsing_map.c srcs/parsing_text_color.c \
		srcs/check_color.c srcs/find_char_map.c \
		srcs/error_msg.c srcs/check_zero.c srcs/init_player.c \
		srcs/check_nb_player_map.c srcs/init_player_position.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

all: $(NAME)

dependency:
	make -sC Libft
	make -sC MLX42

.c.o:
	gcc $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): dependency $(OBJ)
	gcc $(DANGER) -o $(NAME) $(OBJ) -LLibft -lft -LMLX42 -lmlx42
	
clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -sC Libft

re: fclean all

test: all
	@./$(NAME)
	@make fclean

# PROTECTION #

.PHONY: all dependency clean fclean aclean re