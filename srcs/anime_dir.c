/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:31:56 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/12 19:34:40 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	anim_direction_2(t_game *legende, int key)
{
	int	wi;
	int	he;

	if (key == TOUCH_W || key == TOUCH_UP)
		legende->img.mlx_img = mlx_xpm_file_to_image(legende->mlx_ptr, \
		"./image_XPM/croix_verte_nord.xpm", &wi, &he);
	else if (key == TOUCH_S || key == TOUCH_DOWN)
		legende->img.mlx_img = mlx_xpm_file_to_image(legende->mlx_ptr, \
		"./image_XPM/croix_verte_sud.xpm", &wi, &he);
	else if (key == TOUCH_A)
		legende->img.mlx_img = mlx_xpm_file_to_image(legende->mlx_ptr, \
			"./image_XPM/croix_verte_ouest.xpm", &wi, &he);
	else if (key == TOUCH_D)
		legende->img.mlx_img = mlx_xpm_file_to_image(legende->mlx_ptr, \
			"./image_XPM/croix_verte_est.xpm", &wi, &he);
}

void	anim_direction(t_game *legende, int key)
{
	int	wi;
	int	he;

	mlx_destroy_image(legende->mlx_ptr, legende->img.mlx_img);
	legende->img.mlx_img = mlx_new_image(legende->mlx_ptr, 162, 159);
	if (key == TOUCH_RIGHT)
		legende->img.mlx_img = mlx_xpm_file_to_image(legende->mlx_ptr, \
			"./image_XPM/Rotation_droite_vert.xpm", &wi, &he);
	else if (key == TOUCH_LEFT)
		legende->img.mlx_img = mlx_xpm_file_to_image(legende->mlx_ptr, \
			"./image_XPM/Rotation_gauche_vert.xpm", &wi, &he);
	else
		anim_direction_2(legende, key);
	mlx_put_image_to_window(legende->mlx_ptr, legende->wind_ptr, \
		legende->img.mlx_img, CUBE_X + 64, 403);
	mlx_do_sync(legende->mlx_ptr);
}