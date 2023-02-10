/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_player_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:54:50 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/10 16:03:34 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int count_char(char *str, char c)
{
    int x;
    int count;

    x = 0;
    count = 0;
    while (str[x] != '\0' && ft_isprint(str[x]) != '\0')
    {
        if (str[x] == c)
            count++;
        x++;
    }
    return (count);
}

void    check_nb_player_map(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.raws)
    {
        game->map.nb_player += count_char(game->map.tab[i], 'N');
        game->map.nb_player += count_char(game->map.tab[i], 'E');
        game->map.nb_player += count_char(game->map.tab[i], 'S');
        game->map.nb_player += count_char(game->map.tab[i], 'W');
        if (game->map.nb_player == 1)
            init_player_position(game, game->map.tab[i], i);
        i++;
    }
    game->map.nb_player = find_start_pos(NULL, game);
    printf("nb playeur = %i\n", game->map.nb_player);
    if (game->map.nb_player == 1)
        printf("un joueur actif\n");
        
    else 
        error_msg("zero ou plusieur joueur initaliser");
}