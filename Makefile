# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:15:08 by chajjar           #+#    #+#              #
#    Updated: 2023/02/09 21:13:06 by charleshajj      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC_FOLDER = srcs
SRC_FILES =	main check_map \
		parsing_map parsing_text_color \
		check_color find_char_map \
		error_msg check_zero init_player \
		check_nb_player_map init_player_position \
		init_gameplay print_map

SRC = $(foreach f, $(SRC_FILES), $(SRC_FOLDER)/$(f).c)
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

all: $(NAME)

dependency:
	make -sC Libft
	make -sC MLX42
	make -sC mlx

.c.o:
	gcc $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): dependency $(OBJ)
	gcc $(DANGER) -o $(NAME) $(OBJ) -LLibft -lft -LMLX42 -lmlx42 -lglfw 
	gcc $(DANGER) -o $(NAME) $(OBJ) -LLibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
	
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