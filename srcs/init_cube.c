/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:03:07 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 04:30:44 by charleshajj      ###   ########.fr       */
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
	cube->win_ptr = game->win_ptr;
	cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y);
	cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp, \
		&cube->img.line_len, &cube->img.endian);
	ft_border(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img.mlx_img, \
	0, 0);
	mlx_string_put(cube->mlx_ptr, cube->win_ptr, 400, 350, 0xFF0000, \
	"TEST IMG");
	printf("init cube OK\n");
}
