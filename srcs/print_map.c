/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:44:42 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/09 20:50:47 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	show_square(uint32_t x, uint32_t y, mlx_image_t *i)
{
	uint32_t	dx;
	uint32_t	dy;
	uint8_t		*b;

	dy = y * 10;
	while (dy < y * 10 + 10 && dy < i->height)
	{
		dx = x * 10;
		while (dx < x * 10 + 10 && dx < i->width)
		{
			b = &i->pixels[(dx++ + dy * i->width) * 4];
			*b++ = 0xFF;
			*b++ = 0xFF;
			*b++ = 0xFF;
			*b = 0xFF;
		}
		dy++;
	}
}

void	print_map(t_game *g)
{
	int		x;
	int		y;

	y = 0;
	while (g->map.tab && g->map.tab[y])
	{
		x = 0;
		while (g->map.tab[y][x])
		{
			if (g->map.tab[y][x] == '1')
				show_square(x, y, g->img.mlx_img);
			x++;
		}
		y++;
	}
	mlx_image_to_window(g->mlx_ptr, g->img.mlx_img, 0, 0);
}