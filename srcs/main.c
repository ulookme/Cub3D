/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:37 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/14 05:19:55 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_image	images;

	srand(time(0));
	check_file_map_parsing(&images.game, argc, argv);
	parse_data_and_map(&images.game, &images.cube);
	parse_data_and_map2(&images.game);
	check_parameters_map(&images.game);
	init_var_player(&images.game);
	check_nb_player(&images.game);
	init_game(&images.game);
	print_map(&images.game);
	init_legend(&images.game, &images.legend);
	init_cube(&images.game, &images.cube);
	init_text(&images.cube);
	mlx_hook(images.game.win_ptr, 2, 1L << 0, *input, &images);
	mlx_hook(images.game.win_ptr, 17, 1L << 17, ft_close, &images);
	mlx_hook(images.game.win_ptr, 6, 1, *move_test, &images);
	mlx_mouse_hook(images.game.win_ptr, *movements_mouse, &images);
	mlx_loop(images.game.mlx_ptr);
}
