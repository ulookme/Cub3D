/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:24:15 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/08 10:45:06 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int find_player(char *p, char *caracters)
{
    int i;

    i = 0;
    while (caracters[i] != '\0')
    {
        if (p == caracters[i])
            return (1);
        i++;
    }
    return (0);
}

void    init_player_position(t_game *game,char *line, int y)
{
    int x;

    x = 0;
    while ((line[x] != '\0') && find_player(line[x], "NSEW") == 0)
    x++;
    if (line[x] == 0)
        return ;
    game->map.p.x_pos = x * game->rapport_player;
    game->map.p.y_pos = y * game->rapport_player;
}