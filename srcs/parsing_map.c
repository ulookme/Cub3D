/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:19:04 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/05 22:30:20 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_map_line(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.raws)
	{
		if (game->map.columns < (int)ft_strlen(game->map.tab[i]))
			game->map.columns = ft_strlen(game->map.tab[i]);
	}
}

int	parse_map_line2(t_game *game)
{
	int	map_fd;

	map_fd = open(game->reading, O_RDONLY);
	free(game->reading);
	if (map_fd < 0)
		error_msg("la map n'as pas pue etre lu");
	game->reading = get_next_line(map_fd);
	return (map_fd);
}

static void	check_error(t_game *game)
{
	if (game->map.tab[0] == NULL)
		error_msg("map vide");
	if (!find_start_pos(NULL, game))
		error_msg("aucun point de depart");
}

static void	parsing_map_alt(t_game *game, char **tmp, char *tmp2, int map_fd)
{
	if (game->parse.reading_map == 1)
	{
		if (is_empty_line(game->reading))
			error_msg("le map contien une ligne vide");
		if (find_start_pos(game->reading, game) > 1)
			error_msg("la map contient plusieurs point de depart");
		tmp2 = *tmp;
		*tmp = ft_strjoin(tmp2, game->reading);
		free(tmp2);
		game->map.raws += 1;
	}
	if (parse_flag(game) < 0)
	{
		error_msg("la carte contient une instruction duplique");
		close(map_fd);
		game->map.tab = ft_split(*tmp, '\n');
		return ;
	}
	game->reading = get_next_line(map_fd);
}

void	parsing_map(t_game *game, t_game *cube)
{
	int		map_fd;
	char	*tmp;
	char	*tmp2;

	map_fd = parse_map_line2(game);
	if (!game->reading)
		return ;
	tmp2 = NULL;
	tmp = ft_strdup("");
	while (game->reading)
	{
		if (game->parse.reading_map == 0)
			parse_text_color(game->reading, cube, game);
		parsing_map_alt(game, &tmp, tmp2, map_fd);
	}
	close(map_fd);
	game->map.tab = ft_split(tmp, '\n');
	check_error(game);
}
