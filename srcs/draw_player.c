/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:35:10 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/10 17:20:53 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_player(t_game *game, int posx, int posy, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->wind_ptr == NULL)
		return ;
	while (++i < 10 - 1)
	{
		while (++j < 10 - 1)
		{
			if (game->wind_ptr != NULL)
				img_pix_put(game, posy + i, posx + j, color);
		}
		j = 0;
	}
}

void	draw_player_p(t_game *game, int x, int y)
{
	if (game->map.tab[x][y] == NORTH)
	{
		draw_square(game, x * 10, y * 10, FLOOR_COLOR);
		draw_player(game, x * 10, y * 10, NORTH_COLOR);
	}
	else if (game->map.tab[x][y] == SOUTH)
	{
		draw_square(game, x * 10, y * 10, FLOOR_COLOR);
		draw_player(game, x * 10, y * 10, SOUTH_COLOR);
	}
	else if (game->map.tab[x][y] == EAST)
	{
		draw_square(game, x * 10, y * 10, FLOOR_COLOR);
		draw_player(game, x * 10, y * 10, EAST_COLOR);
	}
	else if (game->map.tab[x][y] == WEST)
	{
		draw_square(game, x * 10, y * 10, FLOOR_COLOR);
		draw_player(game, x * 10, y * 10, WEST_COLOR);
	}
}

