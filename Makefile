# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:15:08 by chajjar           #+#    #+#              #
#    Updated: 2023/02/12 22:04:25 by charleshajj      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC_FOLDER = srcs
SRC_FILES =	main check_map \
		parsing_map parsing_text_color \
		check_color find_char_map \
		error_msg check_zero init_player \
		check_nb_player_map init_player_position \
		init_gameplay print_map draw_player color_funct draw_sqard \
		img_pixel_put  events calcul_texture cub_3d_box \
		cub_3d_box2 cub_3d_box3 anime_dir input movement_player ft_close \
		anime_legende init_cube

SRC = $(foreach f, $(SRC_FILES), $(SRC_FOLDER)/$(f).c)
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

all: $(NAME)

dependency:
	make -sC Libft
	make -sC mlx

.c.o:
	gcc $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): dependency $(OBJ)
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