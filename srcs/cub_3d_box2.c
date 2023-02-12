/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d_box2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:13:13 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/12 18:36:00 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_check_wall(t_game *cube)
{
	if (cube->r.raydirx < 0)
	{
		cube->r.stepx = -(1);
		cube->r.sidedistx = (cube->r.posx - cube->r.mapx) * cube->r.deltadistx;
	}
	else
	{
		cube->r.stepx = 1;
		cube->r.sidedistx = (cube->r.mapx + 1.0 - cube->r.posx)
			* cube->r.deltadistx;
	}
	if (cube->r.raydiry < 0)
	{
		cube->r.stepy = -(1);
		cube->r.sidedisty = (cube->r.posy - cube->r.mapy) * cube->r.deltadisty;
	}
	else
	{
		cube->r.stepy = 1;
		cube->r.sidedisty = (cube->r.mapy + 1.0 - cube->r.posy)
			* cube->r.deltadisty;
	}
}

void	ft_init_var_3d_1(t_game *cube, int x)
{
	cube->r.camerax = 2.0 * x / (double)CUBE_X - 1;
	cube->r.raydirx = cube->r.dirx + cube->r.planex * cube->r.camerax;
	cube->r.raydiry = cube->r.diry + cube->r.planey * cube->r.camerax;
	cube->r.mapx = (int)(cube->r.posx);
	cube->r.mapy = (int)(cube->r.posy);
	if (cube->r.raydirx == 0)
		cube->r.deltadistx = 1e30;
	else
		cube->r.deltadistx = fabs(1 / cube->r.raydirx);
	if (cube->r.raydiry == 0)
		cube->r.deltadisty = 1e30;
	else
		cube->r.deltadisty = fabs(1 / cube->r.raydiry);
	cube->r.hit = 0;
	ft_check_wall(cube);
}

static void	init_draw(t_im *images, t_game *cube)
{
	if (cube->r.side == 0)
		cube->r.perpwalldist = (cube->r.sidedistx - cube->r.deltadistx);
	else
		cube->r.perpwalldist = (cube->r.sidedisty - cube->r.deltadisty);
	cube->r.lineheight = (int)(CUBE_Y / cube->r.perpwalldist
			* images->game.rapport_player);
	cube->r.drawstart = -cube->r.lineheight / 2 + CUBE_Y / 2;
	if (cube->r.drawstart < 0)
		cube->r.drawstart = 0;
	cube->r.drawend = cube->r.lineheight / 2 + CUBE_Y / 2;
	if (cube->r.drawend >= CUBE_Y)
		cube->r.drawend = CUBE_Y - 1;
}

static void	test_hit_2(t_im *images, t_game *cube, char *texture_hit)
{
	if (images->game.map.tab[(int)(cube->r.mapy
			/ images->game.rapport_player)][(int)(cube->r.mapx /
					images->game.rapport_player)] >= WALL
			&& images->game.map.tab[(int)(cube->r.mapy /
				images->game.rapport_player)][(int)(cube->r.mapx /
					images->game.rapport_player)] <= '9')
	{
		*texture_hit = images->game.map.tab[(int)(cube->r.mapy
				/ images->game.rapport_player)][(int)(cube->r.mapx
				/ images->game.rapport_player)];
		cube->r.hit = 1;
	}
}

void	calc_dist(t_im *images, t_game *cube, char *texture_hit)
{
	while (cube->r.hit == 0)
	{
		if (cube->r.sidedistx < cube->r.sidedisty)
		{
			cube->r.sidedistx += cube->r.deltadistx;
			cube->r.mapx += cube->r.stepx;
			cube->r.side = 0;
		}
		else
		{
			cube->r.sidedisty += cube->r.deltadisty;
			cube->r.mapy += cube->r.stepy;
			cube->r.side = 1;
		}
		test_hit_2(images, cube, texture_hit);
	}
	init_draw(images, cube);
}