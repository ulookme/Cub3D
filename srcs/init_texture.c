/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:12:16 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 04:35:55 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	calc_texture(double x_map, int i, t_image *images, int face)
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
		images->cube.img_text[face].line_len + x_text * \
		(images->cube.img_text[face].bpp / 8));
	return (*(unsigned int *) pixel);
}

void	init_text(t_game *cube)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		cube->img_text[i].mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
			cube->name_text[i], \
			&cube->img_text[i].size.x, &cube->img_text[i].size.y);
		if (!cube->img_text[i].mlx_img)
			error_msg("error:\n texture non trouvee");
		cube->img_text[i].addr = mlx_get_data_addr(cube->img_text[i].mlx_img, \
			&cube->img_text[i].bpp, \
			&cube->img_text[i].line_len, &cube->img_text[i].endian);
		printf("texture OK\n");
	}
}