/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:11:19 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 03:31:55 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	index_last_line(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	while (game->map.tab[i])
		i++;
	size = i;
	return (size);
}

int	find_char_map(char p, char *caracters)
{
	int	i;

	i = 0;
	while (caracters[i] != '\0')
	{
		if (p == caracters[i])
			return (1);
	i++;
	}
	return (0);
}

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

int	check_parameters_map(t_game *game)
{
	if (check_map_char(game) == 0)
		error_msg("Error:\ncaractère non défini dans la map !");
	if (check_border_map(game) == 0)
		error_msg("Error:\nla map est ouverte sur les bords !");
	if (check_zeros(game) == 0)
		error_msg("Error:\nla map est ouverte à l'interieur !");
	printf("maps OK\n");
	return (0);
}

