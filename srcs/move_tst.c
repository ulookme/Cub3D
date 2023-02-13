/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:02:13 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/13 04:04:38 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_move_test_2(int x, t_im *images, int *key)
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
	mlx_mouse_move(images->game.wind_ptr, (CUBE_X / 2), CUBE_Y - 100);
}

int	move_test(int x, int y, t_im *images)
{
	int	key;

	key = TOUCH_RIGHT;
	if (x > CUBE_X || y > CUBE_Y)
		return (0);
	ft_move_test_2(x, images, &key);
	anim_direction(&images->legende, key);
	if (images->game.wind_ptr == NULL)
		return (1);
	anim_legend(&images->legende);
	anim_cub3d(images);
	reprint_pos(&images->game);
	return (0);
}