/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:32:22 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/14 03:04:16 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	c_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (0);
	return (1);
}

int	check_zeros(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < game->map.lines - 1)
	{
		while (++j < (int)(ft_strlen(game->map.tab[i]) - 1))
		{
			if (find_char_map(game->map.tab[i][j], "0NSEW"))
			{
				if (c_space(game->map.tab[i + 1][j]) == 0 \
					|| c_space(game->map.tab[i + 1][j + 1]) == 0 \
					|| c_space(game->map.tab[i + 1][j - 1]) == 0 \
					|| c_space(game->map.tab[i][j + 1]) == 0 \
					|| c_space(game->map.tab[i][j - 1]) == 0 \
					|| c_space(game->map.tab[i - 1][j]) == 0 \
					|| c_space(game->map.tab[i - 1][j + 1]) == 0 \
					|| c_space(game->map.tab[i - 1][j - 1]) == 0)
					return (0);
			}			
		}
		j = 0;
	}
	return (1);
}
