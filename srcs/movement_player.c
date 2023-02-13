/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:18:25 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/12 19:21:19 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_push_key(t_im *image, t_game *game, int key)
{
	if (key == TOUCH_W || key == TOUCH_UP)
		move_player(game, -1.0, 0);
	else if (key == TOUCH_S || key == TOUCH_DOWN)
		move_player(game, 1.0, 0);
	else if (key == TOUCH_A)
	{
		image->cube.dir_sprite = 0;
		move_player(game, 1.0, (M_PI / 2));
	}
	else if (key == TOUCH_D)
	{
		image->cube.dir_sprite = 1;
		move_player(game, 1.0, -(M_PI / 2));
	}
	else if (key == TOUCH_ESC)
		ft_close(image);
}

void	update(t_im *image, int key)
{
	t_game	*game;

	game = &image->game;
	if (key == TOUCH_RIGHT)
	{
		image->cube.dir_sprite = 1;
		game->map.p.apos += game->map.p.rot;
		if (game->map.p.apos >= 2 * M_PI)
			game->map.p.apos = game->map.p.apos - (2 * M_PI);
	}
	else if (key == TOUCH_LEFT)
	{
		image->cube.dir_sprite = 0;
		game->map.p.apos -= game->map.p.rot;
		if (game->map.p.apos < 0)
			game->map.p.apos = (2 * M_PI) + game->map.p.apos;
	}
	else
		ft_push_key(image, game, key);
}

static void	ft_init_pos(t_game *game, double alpha, double *apos)
{
	*apos = game->map.p.apos + alpha;
	if (*apos < 0)
		*apos = (2 * M_PI) + *apos;
	if (*apos > 2 * M_PI)
		*apos = *apos - (2 * M_PI);
	game->map.p.x_pos = game->map.p.x_pos / game->rapport_player * 10;
	game->map.p.y_pos = game->map.p.y_pos / game->rapport_player * 10;
}

static void	ft_test_move_2(t_game *game, double nb, double apos)
{
	double	tmp_y;

	tmp_y = game->map.p.y_pos + (game->map.p.speed * sin(apos)) * nb;
	if (game->map.tab[(int)floor(tmp_y / 10)][(int)floor(game->map.p.x_pos / \
			10)] == FLOOR && game->map.tab[(int)floor(tmp_y / \
			10)][(int)floor(game->map.p.x_pos / 10) + 1] == FLOOR && \
			game->map.tab[(int)floor(tmp_y / 10) + 1] \
			[(int)floor(game->map.p.x_pos / 10)] == FLOOR && \
			game->map.tab[(int)floor(tmp_y / 10) + 1] \
			[(int)floor(game->map.p.x_pos / 10) + 1] == FLOOR)
		game->map.p.y_pos = tmp_y;
	else
		game->map.hit_wall = 1;
}

void	move_player(t_game *game, double nb, double alpha)
{
	double	tmp_x;
	double	apos;

	ft_init_pos(game, alpha, &apos);
	tmp_x = game->map.p.x_pos + (game->map.p.speed * cos(apos)) * nb;
	if (game->map.tab[(int)floor(game->map.p.y_pos / 10)][(int)floor(tmp_x / \
			10)] == FLOOR && game->map.tab[(int)floor(game->map.p.y_pos / \
			10) + 1][(int)floor(tmp_x / 10)] == FLOOR && \
			game->map.tab[(int)floor(game->map.p.y_pos / \
			10)][(int)floor(tmp_x / 10) + 1] == FLOOR && \
			game->map.tab[(int)floor(game->map.p.y_pos / 10) + \
			1][(int)floor(tmp_x / 10) + 1] == FLOOR)
		game->map.p.x_pos = tmp_x;
	else
		game->map.hit_wall = 1;
	ft_test_move_2(game, nb, apos);
	game->map.p.x_pos = game->map.p.x_pos / 10 * game->rapport_player;
	game->map.p.y_pos = game->map.p.y_pos / 10 * game->rapport_player;
}