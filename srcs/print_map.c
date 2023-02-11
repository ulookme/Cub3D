/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:44:42 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/11 23:10:01 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	test_size_map2(t_game *game)
{
	if (game->wind_ptr == NULL)
		return (1);
	if (game->textsize == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->wind_ptr, \
			game->img.mlx_img, 0, CUBE_Y);
		mlx_string_put(game->mlx_ptr, game->wind_ptr, 100, CUBE_Y + 100, \
			encode_rgb(0, 255, 0), "*** TOO LARGE *** ");
		return (0);
	}
	return (0);
}

static void	ft_put_wall_player(t_game *game, int x, int y)
{
	int	wi;
	int	he;

	if (game->map.tab[x][y] >= WALL && game->map.tab[x][y] <= '9'
		&& (game->textsize))
	{
		game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./image_XPM/wall.xpm", &wi, &he);
		mlx_put_image_to_window(game->mlx_ptr, game->wind_ptr, \
			game->img.mlx_img, y * 10, x * 10 + CUBE_Y);
	}
	if (find_player(game->map.tab[x][y], "NSEW") == 1)
	{
		if (game->textsize)
			draw_player_p(game, x, y);
		game->map.tab[(int)floor(game->map.p.y_pos / \
			game->rapport_player)][(int)floor(game->map.p.x_pos / \
				game->rapport_player)] = FLOOR;
	}	
}

int	print_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	if (test_size_map2(game))
		return (1);
	while (++x < game->map.raws)
	{
		y = -1;
		while (game->map.tab[x][++y])
			ft_put_wall_player(game, x, y);
	}
	return (0);
}

