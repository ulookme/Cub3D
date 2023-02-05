/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_charac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:31:28 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/05 21:04:59 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_map_char(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->map.tab[++i])
	{
		while (game->map.tab[i][++j])
		{
			if (find_char_map(game->map.tab[i][j], " \t01NSEW") == 0)
				return (0);
		}
		j = -1;
	}
	return (1);
}