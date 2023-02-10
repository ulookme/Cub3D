/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:48:32 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/10 17:05:44 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_test_size_map(t_game *game)
{
	int	i;

	game->map.columns = 0;
	i = -1;
	while (game->map.tab[++i])
		if ((int)ft_strlen(game->map.tab[i]) > game->map.columns)
			game->map.columns = ft_strlen(game->map.tab[i]);
	if (game->map.columns * 10 < IMAGE_X && game->map.raws * \
			10 < IMAGE_Y - CUBE_Y)
	{
		game->textsize = 1;
		game->img.mlx_img = mlx_new_image(game->mlx_ptr, (game->map.columns * \
			10), (game->map.raws * 10));
		game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp, \
			&game->img.raw_len, &game->img.endian);
	}
	else
	{
		game->textsize = 0;
		game->img.mlx_img = mlx_new_image(game->mlx_ptr, IMAGE_X - \
			LEGENDE_X, IMAGE_Y - CUBE_Y);
		game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp, \
			&game->img.raw_len, &game->img.endian);
	}
}

void	init_game(t_game *game)
{
	int	x;
	int	y;

	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		error_msg("pointeur mlx introuvable");
	x = IMAGE_X;
	y = IMAGE_Y;
	game->wind_ptr = mlx_new_window(game->mlx_ptr, x, y, "Cub3D");
	if (game->wind_ptr == NULL)
	{
		free(game->wind_ptr);
		error_msg("fenetre introuvable");
	}
	ft_test_size_map(game);
}