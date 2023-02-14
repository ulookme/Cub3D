/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:11:51 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 04:43:31 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	input_2(t_image *images)
{
	input(TOUCH_W, images);
	return (0);
}

int	input(int key, t_image *images)
{
	t_game	*game;

	game = &images->game;
	update(images, key);
	anim_direction(&images->legend, key);
	if (game->win_ptr == NULL)
		return (1);
	anim_cub3d(images);
	reprint_pos(game);
	return (0);
}