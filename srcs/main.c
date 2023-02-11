/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:37 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/11 23:25:44 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_im	images;

	srand(time(0));
	check_file_map_parsing(&images.game, argc, argv);
	parsing_map(&images.game, &images.cube);
	parse_map_line(&images.game);
	check_parametre_map(&images.game);
	init_player(&images.game);
	check_nb_player_map(&images.game);
	init_game(&images.game);
	print_map(&images.game);
	init_legend(&images.game, &images.legende);
	mlx_hook(images.game.wind_ptr, 17, 1L << 17, event_close, \
		"Application closed\n");
	mlx_key_hook(images.game.wind_ptr, event_key, &images.game);
	mlx_loop(images.game.mlx_ptr);
}
