/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_text_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:01:40 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/08 15:57:16 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	find_texture(char *path, int index, t_game *cube)
{	
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(path, ' ');
	tmp[1][ft_strlen(tmp[1]) - 1] = '\0';
	if (!tmp[1] || tmp[2])
		error_msg("impossible de charger la texture");
	cube->name_text[index] = ft_strdup(tmp[1]);
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (1);
}

int	find_cell_color(char *path, t_game *cube)
{
	char	**tmp1;
	char	**tmp2;
	int		i;

	i = -1;
	tmp1 = ft_split(path, ' ');
	if (!tmp1[1] || tmp1[2])
		error_msg("impossible de charger la couleur du plafond");
	tmp2 = ft_split(path, ',');
	if (!tmp2[2] || tmp2[3])
		error_msg("impossible de charger la couleur du plafond");
	cube->r_c = ft_atoi(tmp2[0]);
	cube->b_c = ft_atoi(tmp2[1]);
	cube->g_c = ft_atoi(tmp2[2]);
	if (!check_color(cube->r_c, cube->g_c, cube->b_c))
		error_msg("chargement du plafond impossible");
	while (tmp1[++i])
		free(tmp1[i]);
	free(tmp1);
	i = -1;
	while (tmp2[++i])
		free(tmp2[i]);
	free(tmp2);
	return (1);
}

int	find_start_pos(const char *str, t_game *cube)
{
	int			x;
	static int	y = 0;
	static int	spawns = 0;

	x = 0;
	while (str && str[x] && str[x] != '\n')
	{
		if (str[x] == 'E' || str[x] == 'N'
			|| str[x] == 'S' || str[x] == 'W')
		{
			cube->player.x_pos = x;
			cube->player.y_pos = y;
			spawns++;
		}
		if (str[x] == 'E')
			cube->player.rot = 0;
		if (str[x] == 'N')
			cube->player.rot = 90;
		if (str[x] == 'W')
			cube->player.rot = 180;
		if (str[x++] == 'S')
			cube->player.rot = 260;
	}
	if (str)
		y++;
	return (spawns);
}

int	find_floor_color(char *path, t_game *cube)
{
	char	**tmp1;
	char	**tmp2;
	int		i;

	i = -1;
	tmp1 = ft_split(path, ' ');
	if (!tmp1[1] || tmp1[2])
		error_msg("impossible de charger la couleur du sol");
	tmp2 = ft_split(path, ',');
	if (!tmp2[2] || tmp2[3])
		error_msg("impossible de charger la couleur du sol");
	cube->r_f = ft_atoi(tmp2[0]);
	cube->b_f = ft_atoi(tmp2[1]);
	cube->g_f = ft_atoi(tmp2[2]);
	if (!check_color(cube->r_f, cube->g_f, cube->b_f))
		error_msg("chargement du sol impossible");
	while (tmp1[++i])
		free(tmp1[i]);
	free(tmp1);
	i = -1;
	while (tmp2[++i])
		free(tmp2[i]);
	free(tmp2);
	return (1);
}

void	parse_text_color(char *path, t_game *cube, t_game *game)
{
	if (path[0] == 'N' && path[1] == 'O')
		game->parse.flag_n += find_texture(path, 0, cube);
	else if (path[0] == 'S' && path[1] == 'O')
		game->parse.flag_s += find_texture(path, 1, cube);
	else if (path[0] == 'E' && path[1] == 'A')
		game->parse.flag_e += find_texture(path, 3, cube);
	else if (path[0] == 'W' && path[1] == 'E')
		game->parse.flag_w += find_texture(path, 2, cube);
	else if (path[0] == 'F')
		game->parse.flag_f += find_floor_color(path, cube);
	else if (path[0] == 'C')
		game->parse.flag_c += find_cell_color(path, cube);
	else if (parse_flag(game) && !is_empty_line(path))
		game->parse.reading_map = 1;
}
