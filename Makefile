# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:15:08 by chajjar           #+#    #+#              #
#    Updated: 2023/02/14 07:28:09 by charleshajj      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC_FOLDER = srcs
SRC_FILES =	main check_map \
		parsing_map parsing_text_color \
		find_char init_player find_player\
		error_msg check_zero  check_nb_player_map\
		check_border parse_utils init_gameplay\
		color_funct print_map  draw_player movement_player\
		img_pixel_put draw_sqard anime_legende\
		init_cube init_texture input ft_close\
		mouve_mss anime_dir cub_3d_box3 cub_3d_box\
		cub_3d_box2\
		

SRC = $(foreach f, $(SRC_FILES), $(SRC_FOLDER)/$(f).c)
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3

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