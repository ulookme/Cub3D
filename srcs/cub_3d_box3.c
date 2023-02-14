/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d_box3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:13:39 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 05:02:58 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_floor_sky(t_image *images, t_game *cube)
{
	int	i;
	int	j;

	cube->r.posx = images->game.map.p.pos.x;
	cube->r.posy = images->game.map.p.pos.y;
	cube->r.dirx = -(cos(images->game.map.p.apos));
	cube->r.diry = -(sin(images->game.map.p.apos));
	cube->r.planex = sin(images->game.map.p.apos) * 0.66;
	cube->r.planey = cos(images->game.map.p.apos) * -0.66;
	i = 0;
	while (i < CUBE_X)
	{
		j = -1;
		while (++j < CUBE_Y)
		{
			if (j < CUBE_Y / 2)
				img_pix_put(cube, i, j, encode_rgb(cube->r_c, \
				cube->b_c, cube->g_c));
			else
				img_pix_put(cube, i, j, encode_rgb(cube->r_f, \
				cube->b_f, cube->g_f));
		}
		i++;
	}
}

int	anim_cub3d(t_image *images)
{
	t_game	*cube;
	char	texture_hit;

	cube = &images->cube;
	mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
	cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y);
	cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp,
			&cube->img.line_len, &cube->img.endian);
	init_floor_sky(images, cube);
	cube->r.x = 0;
	while (cube->r.x < CUBE_X)
	{
		ft_init_var_3d_1(cube, cube->r.x);
		ft_calc_dist(images, cube, &texture_hit);
		ft_choice_texture(images, cube, &texture_hit);
	}
	ft_clear_logo_direction(images, cube);
	return (0);
}