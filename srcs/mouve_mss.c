/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_mss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:05:42 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 04:55:01 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_move_test_2(int x, t_image *images, int *key)
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
		images->cube.dir_sprite = 1;
	}
}

int	move_test(int x, int y, t_image *images)
{
	int	key;

	key = TOUCH_RIGHT;
	if (x > CUBE_X || y > CUBE_Y)
		return (0);
	ft_move_test_2(x, images, &key);
	anim_direction(&images->legend, key);
	if (images->game.win_ptr == NULL)
		return (1);
	anim_legend(&images->legend);
	anim_cub3d(images);
	reprint_pos(&images->game);
	return (0);
}

static void	ft_move_mouse_2(int x, t_image *images, int *key)
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
}

int	movements_mouse(int button, int x, int y, t_image *images)
{
	int	key;

	(void) button;
	key = TOUCH_RIGHT;
	images->cube.dir_sprite = 1;
	if (x > CUBE_X || y > CUBE_Y)
		return (0);
	ft_move_mouse_2(x, images, &key);
	anim_direction(&images->legend, key);
	if (images->game.win_ptr == NULL)
		return (1);
	anim_legend(&images->legend);
	anim_cub3d(images);
	reprint_pos(&images->game);
	return (0);
}