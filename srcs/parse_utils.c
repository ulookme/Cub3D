/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:05:35 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 03:19:59 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_flag(t_game *game)
{
	if (game->parse.flag_n == 0 || game->parse.flag_s == 0 \
		|| game->parse.flag_w == 0 || game->parse.flag_e == 0 \
		|| game->parse.flag_c == 0 || game->parse.flag_f == 0)
		return (0);
	return (1);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_color(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}