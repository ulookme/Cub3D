/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:04:05 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/12 20:04:36 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_close(t_im *image)
{
	t_game	*game;
	int		i;

	game = &image->game;
	mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	mlx_destroy_image(image->legende.mlx_ptr, image->legende.img.mlx_img);
	mlx_destroy_image(image->cube.mlx_ptr, image->cube.img.mlx_img);
	mlx_destroy_window(game->mlx_ptr, game->wind_ptr);
	free(game->mlx_ptr);
	i = -1;
	while (image->game.map.tab[++i])
		free(image->game.map.tab[i]);
	free(image->game.map.tab);
	i = -1;
	while (++i < 4)
		free(image->cube.name_text[i]);
	exit (0);
}