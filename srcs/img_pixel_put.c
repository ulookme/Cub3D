/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:31 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 04:09:24 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	img_pix_put(t_game *game, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = game->img.bpp - 8;
	pixel = game->img.addr + (y * game->img.line_len + x * \
		(game->img.bpp / 8));
	while (i >= 0)
	{
		if (game->img.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (game->img.bpp - 8 - i)) & 0xFF;
				i -= 8;
	}
}