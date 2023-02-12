/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:03:07 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/12 22:03:35 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_border(t_game *cube)
{
	int	i;

	i = 0;
	while (i < CUBE_Y - 10)
	{
		draw_square(cube, i, 0, WALL_COLOR);
		draw_square(cube, i, CUBE_X - 10, WALL_COLOR);
		i += 10;
	}
	i = 0;
	while (i < CUBE_X)
	{
		draw_square(cube, 0, i, WALL_COLOR);
		draw_square(cube, CUBE_Y - 10, i, WALL_COLOR);
		i += 10;
	}
}

void	init_cube(t_game *game, t_game *cube)
{
	cube->mlx_ptr = game->mlx_ptr;
	cube->wind_ptr = game->wind_ptr;
	cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y);
	cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp, \
		&cube->img.raw_len, &cube->img.endian);
	ft_border(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->wind_ptr, cube->img.mlx_img, \
	0, 0);
	mlx_string_put(cube->mlx_ptr, cube->wind_ptr, 250, 300, 0x00FF00, \
	"***  VIEW 3D  ***");
	mlx_string_put(cube->mlx_ptr, cube->wind_ptr, 250, 320, 0x00FF00, \
	"    Waiting ...");
}