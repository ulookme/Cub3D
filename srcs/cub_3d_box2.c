/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d_box2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:13:13 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 05:13:03 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_choice_pixel_color(t_image *images, t_game *cube)
{
	int	color;
	int	i;

	i = cube->r.drawstart - 1;
	while (++i < cube->r.drawend)
	{
		if (cube->r.side == 1)
			color = calc_texture(cube->r.mapx, i - cube->r.drawstart, \
				images, cube->r.index);
		else
			color = calc_texture(cube->r.mapy, i - cube->r.drawstart, \
				images, cube->r.index);
		img_pix_put(cube, cube->r.x, i, color);
	}
	cube->r.x += 1;
}

void	ft_choice_texture(t_image *images, t_game *cube, char *texture_hit)
{
	if (cube->r.side == 0 && *texture_hit == WALL)
	{
		if (cube->r.posx < cube->r.mapx)
			cube->r.index = 2;
		else
			cube->r.index = 3;
	}
	else if (*texture_hit == WALL)
	{
		if (cube->r.posy < cube->r.mapy)
			cube->r.index = 0;
		else
			cube->r.index = 1;
	}
	else if (*texture_hit == '2')
		cube->r.index = 5;
	else if (*texture_hit == '3')
		cube->r.index = 4;
	else
		cube->r.index = 6;
	ft_choice_pixel_color(images, cube);
}

void	ft_clear_logo_direction(t_image *images, t_game *cube)
{
	t_game	*legend;

	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, \
		cube->img.mlx_img, 0, 0);
	legend = &images->legend;
	mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, \
	legend->img.mlx_img, CUBE_X + 64, 403);
}