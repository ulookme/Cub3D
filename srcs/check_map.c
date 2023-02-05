/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:14:18 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/05 21:57:16 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_file_map_parsing(t_game *game, int argc, char **argv)
{
	int	len_file;

	if (argc != 2)
		error_msg("execution sans le fichier");
	len_file = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len_file - 4], ".cub", 4))
		error_msg("le fichier le contient pas l'extension .cub");
	game->reading = ft_strdup(argv[1]);
	game->parse.flag_c = 0;
	game->parse.flag_n = 0;
	game->parse.flag_e = 0;
	game->parse.flag_f = 0;
	game->parse.flag_s = 0;
	game->parse.flag_w = 0;
	game->parse.reading_map = 0;
	game->map.raws = 0;
}

void	fill_algorithm(int x, int y, char **region)
{
	int		i;

	if (region && y >= 0 && region[y] && x >= 0 && region[y][x])
	{
		if (region[y][x] != '0' && region[y][x] != 'N'
			&& region[y][x] != 'S' && region[y][x] != 'E'
			&& region[y][x] != 'W')
			return ;
		region[y][x] = FILL_CHAR;
		fill_algorithm(x + 1, y, region);
		fill_algorithm(x - 1, y, region);
		fill_algorithm(x, y + 1, region);
		fill_algorithm(x, y - 1, region);
	}
	else
	{
		i = 0;
		printf("Out at: %d %d\n", x, y);
		while (region && region[i])
			printf("%s\n", region[i++]);
		error_msg("la map n est pas entierement ferme");
	}
}

int check_parametre_map(t_game *game)
{
	int		i;

	i = 0;
    if (check_map_char(game) == 0)
        error_msg("caractere non definie dans le map");
    fill_algorithm(game->player.x_pos, game->player.y_pos, game->map.tab);
	while (game->map.tab && game->map.tab[i])
		printf("%s\n", game->map.tab[i++]);
    printf("Success: Map loaded!\n");
    return (0);
}