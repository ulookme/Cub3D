/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:31:56 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 05:01:42 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	anim_direction(t_game *legend, int key)
{
	(void) key;
	mlx_destroy_image(legend->mlx_ptr, legend->img.mlx_img);
	legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, 162, 159);
	mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, \
		legend->img.mlx_img, CUBE_X + 64, 403);
	mlx_do_sync(legend->mlx_ptr);
}