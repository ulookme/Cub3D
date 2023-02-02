/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:19:04 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/02 16:10:39 by chajjar          ###   ########.fr       */
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
	if (map_fd == -1)
		printf("Error: la map n'as pas pue etre lu");
	game->reading = get_next_line(map_fd);
	return (map_fd);
}

void	empty_map(t_game *game)
{
	if (game->map.tab[0] == NULL)
		printf("Error: map vide");
}

void	parsing_map(t_game *game, t_game *cube)
{
	int		map_fd;
	char	*tmp;
	char	*tmp2;

	map_fd = parse_map_line2(game);
	tmp = ft_strdup("");
	while (game->reading)
	{
		if (game->parse.reading_map == 0)
			parse_text_color(game->reading, cube, game);
		if (game->parse.reading_map == 1)
		{
			if (is_empty_line(game->reading))
				prinf("Error: le map contien une ligne vide");
			tmp2 = tmp;
			tmp = ft_strjoin(tmp2, game->reading);
			free(tmp2);
			game->map.raws += 1;
		}
		game->reading = get_next_line(map_fd);
	}
	close(map_fd);
	game->map.tab = ft_split(tmp, '\n');
	empty_map(game);
}
