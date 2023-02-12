/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:11:51 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/12 19:16:56 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	input_2(t_im *images)
{
	input(TOUCH_W, images);
	return (0);
}

int	input(int key, t_im *images)
{
	t_game	*game;

	game = &images->game;
	update(images, key);
	anim_direction(&images->legende, key);
	if (game->wind_ptr == NULL)
		return (1);
	anim_legend(&images->legende);
	anim_cub3d(images);
	reprint_pos(game);
	return (0);
}