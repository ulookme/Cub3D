/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_legend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:49:37 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/11 23:08:15 by charleshajj      ###   ########.fr       */
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
		"./image_XPM/Cub3D1.xpm", &wi, &he);
	if (!legend->img.mlx_img)
		error_msg("failed to load assets!");
}