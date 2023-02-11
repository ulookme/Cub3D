/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_legend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:49:37 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/11 21:51:06 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_legend(t_game *game, t_game *legend)
{
	int	wi;
	int	he;

	legend->mlx_ptr = game->mlx_ptr;
	legend->wind_ptr = game->wind_ptr;
	legend->map.raws = game->map.raws;
	legend->map.columns = game->map.columns;
	legend->map.move = 0;
	legend->apos_game = &(game->map.p.apos);
	legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, LEGENDE_X, LEGENDE_Y);
	legend->img.addr = mlx_get_data_addr(legend->img.mlx_img, &legend->img.bpp \
		, &legend->img.raw_len, &legend->img.endian);
	legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, \
		"./images_xpm/Cube3D_1b.xpm", &wi, &he);
	mlx_put_image_to_window(legend->mlx_ptr, legend->wind_ptr, \
		legend->img.mlx_img, CUBE_X, 0);
}