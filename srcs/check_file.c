/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:21:01 by chajjar           #+#    #+#             */
/*   Updated: 2023/01/31 18:55:39 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_file_map_parsing(t_game *game, int argc, char **argv)
{
	int	len_file;

	if (argc != 2)
		printf("execution sans le fichier");
	len_file = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len_file - 4], ".cub", 4))
		printf("error: le fichier le contient pas l'extension .cub");
	game->reading = ft_strjoin("maps/", argv[1]);
	game->parse.flag_c = 0;
	game->parse.flag_n = 0;
	game->parse.flag_e = 0;
	game->parse.flag_f = 0;
	game->parse.flag_s = 0;
	game->parse.flag_w = 0;
	game->parse.reading_map = 0;
	game->map.raws = 0;
	printf("parsing ok\n");
}