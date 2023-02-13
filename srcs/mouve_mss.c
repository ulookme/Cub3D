/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_mss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:05:42 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/13 04:06:20 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_move_mouse_2(int x, t_im *images, int *key)
{
	double	rapport;
	double	apos_mouse;

	rapport = M_PI / 2.0 / CUBE_X;
	apos_mouse = rapport * x;
	apos_mouse = apos_mouse - (M_PI / 4);
	images->game.map.p.apos = images->game.map.p.apos + apos_mouse;
	if (images->game.map.p.apos < 0)
			images->game.map.p.apos = (2 * M_PI) + images->game.map.p.apos;
	if (images->game.map.p.apos >= 2 * M_PI)
			images->game.map.p.apos = images->game.map.p.apos - (2 * M_PI);
	if (apos_mouse < 0)
	{
		*key = TOUCH_LEFT;
		images->cube.dir_sprite = 0;
	}
	else
	{
		*key = TOUCH_RIGHT;
		images->cube.dir_sprite = 1;
	}
}

int	movements_mouse(int button, int x, int y, t_im *images)
{
	int	key;

	(void) button;
	key = TOUCH_RIGHT;
	images->cube.dir_sprite = 1;
	if (x > CUBE_X || y > CUBE_Y)
		return (0);
	ft_move_mouse_2(x, images, &key);
	anim_direction(&images->legende, key);
	if (images->game.wind_ptr == NULL)
		return (1);
	anim_legend(&images->legende);
	anim_cub3d(images);
	reprint_pos(&images->game);
	return (0);
}