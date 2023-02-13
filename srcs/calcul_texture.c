/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:42:01 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/13 04:53:08 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_calc_texture(double x_map, int i, t_im *images, int face)
{
	double	x;
	char	*pixel;
	int		x_text;
	int		y_text;
	int		height;

	if (images->cube.r.lineheight > CUBE_Y)
		i = i + (images->cube.r.lineheight - CUBE_Y) / 2;
	height = images->cube.r.lineheight;
	x = x_map / (1.0 * (images->game.rapport_player)) - (int)(x_map / \
		(1.0 * (images->game.rapport_player)));
	x_text = (x * images->cube.img_text[face].size.x);
	y_text = (((i * 1.0) / height) * images->cube.img_text[face].size.y);
	pixel = images->cube.img_text[face].addr + (y_text * \
		images->cube.img_text[face].raw_len + x_text * \
		(images->cube.img_text[face].bpp / 8));
	return (*(unsigned int *) pixel);
}