/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_char_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:36:39 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/05 20:14:08 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	index_last_raw(t_game *game)
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