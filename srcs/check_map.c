/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:14:18 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/14 02:18:43 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_file_map_parsing(t_game *game, int argc, char **argv)
{
	int	len_filename;

	if (argc != 2)
		error_msg("Error:\nimpossible d'ouvrir le fichier !");
	len_filename = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len_filename - 4], ".cub", 4))
		error_msg("Error:\nle fichier ne contient pas l'extention .cub");
	game->read_str = ft_strjoin("maps/", argv[1]);
	game->parse.flag_n = 0;
	game->parse.flag_s = 0;
	game->parse.flag_e = 0;
	game->parse.flag_w = 0;
	game->parse.flag_c = 0;
	game->parse.flag_f = 0;
	game->parse.read_map = 0;
	game->map.lines = 0;
}



