/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:19:04 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/01 17:37:17 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_map_line(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.raws)
	{
		if (game->map.columns < (int)ft_strlen(game->map.tab[i]))
			game->map.columns = ft_strlen(game->map.tab[i]);
	}
}

int	parse_map_line2(t_game *game)
{
	int	map_fd;

	
}