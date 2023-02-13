/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:37 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/13 13:52:01 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_im	*images;

	images = malloc(sizeof(t_im));
	srand(time(0));
	check_file_map_parsing(&images->game, argc, argv);
	parsing_map(&images->game, &images->cube);
	parse_map_line(&images->game);
	check_parametre_map(&images->game);
	init_player(&images->game);
	check_nb_player_map(&images->game);
	init_game(&images->game);
	print_map(&images->game);
	init_legend(&images->game, &images->legende);
	init_cube(&images->game, &images->cube);
	//ft_init_text(&images->cube);
	mlx_string_put(images->cube.mlx_ptr, images->cube.wind_ptr, 250, \
		340, 0x00FF00, "       GO");
	mlx_mouse_move(images->game.wind_ptr, (CUBE_X / 2), (CUBE_Y -100));
	mlx_hook(images->game.wind_ptr, 2, 1L << 0, *input, &images);
	mlx_hook(images->game.wind_ptr, 17, 1L << 17, ft_close, &images);
	mlx_hook(images->game.wind_ptr, 6, 1, *move_test, &images);
	mlx_mouse_hook(images->game.wind_ptr, *movements_mouse, &images);
	mlx_loop(images->game.mlx_ptr);
	free(images);
}
