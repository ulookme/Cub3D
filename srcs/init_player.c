/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:07:52 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/08 10:13:48 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    init_pos_player(t_game *game)
{
    int x;
    int y;

    x = -1;
    while (++x < game->map.raws)
    {
        y = -1;
        while (++y < game->map.columns)
        {
            if (game->map.tab[x][y] == SOUTH)
                game->map.p.apos = ((3 * M_PI) / 2);
            else if (game->map.tab[x][y] == EAST)
                game->map.p.apos = M_PI;
            else if (game->map.tab[x][y] == NORTH)
                game->map.p.apos = (M_PI / 2);
            else if (game->map.tab[x][y] == WEST)
                game->map.p.apos = 0;
        }
    }
}

void    init_player(t_game *game)
{
    game->map.nb_player = 0;
    game->map.p.speed = 0.5;
    game->map.p.rot = 0.1;
    game->map.hit_wall = 0;
    game->rapport_player = DEFINITION_TEXTURES;
    init_pos_player(game);
}