/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:12:16 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/13 04:43:20 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_text(t_game *cube)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		cube->img_text[i].mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
			cube->name_text[i], \
			&cube->img_text[i].size.x, &cube->img_text[i].size.y);
		if (!cube->img_text[i].mlx_img)
			error_msg("texture non trouvee");
		cube->img_text[i].addr = mlx_get_data_addr(cube->img_text[i].mlx_img, \
			&cube->img_text[i].bpp, \
			&cube->img_text[i].raw_len, &cube->img_text[i].endian);
	}
}