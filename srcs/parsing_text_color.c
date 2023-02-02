/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_text_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:01:40 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/02 14:20:21 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	find_texture(char *path, int index, t_game *cube)
{	
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(path, ' ');
	tmp[1][ft_strlen(tmp[1]) - 1] = "\0";
	if (!tmp[1] || tmp[2])
		printf("Error: impossible de charger la texture");
	cube->name_text[index] = ft_strlen(tmp[1]);
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
		printf("Error: impossible de charger la couleur du plafond");
	tmp2 = ft_split(path, ',');
	if (!tmp2[2] || tmp2[3])
		printf("Error: impossible de charger la couleur du plafond");
	cube->r_c = ft_atoi(tmp2[0]);
	cube->b_c = ft_atoi(tmp2[1]);
	cube->g_c = ft_atoi(tmp2[2]);
	if (!check_color(cube->r_c, cube->g_c, cube->b_c))
		printf("Error: chargement du plafond impossible");
	while (tmp1[++i])
		free(tmp1[i]);
	free(tmp1);
	i = -1;
	while (tmp2[++i])
		free(tmp2[i]);
	free(tmp2);
	return (1);
}

int	find_floor_color(char *path, t_game *cube)
{
	char	**tmp1;
	char	**tmp2;
	int		i;

	i = -1;
	tmp1 = ft_split(path, ' ');
	if (!tmp1[1] || tmp1[2])
		printf("Error: impossible de charger la couleur du sol");
	tmp2 = ft_split(path, ',');
	if (!tmp2[2] || tmp2[3])
		printf("Error: impossible de charger la couleur du sol");
	cube->r_f = ft_atoi(tmp2[0]);
	cube->b_f = ft_atoi(tmp2[1]);
	cube->g_f = ft_atoi(tmp2[2]);
	if (!check_color(cube->r_f, cube->g_f, cube->b_f))
		printf("Error: chargement du sol impossible");
	while (tmp1[++i])
		free(tmp1[i]);
	free(tmp1);
	i = -1;
	while (tmp2[++i])
		free(tmp2[i]);
	free(tmp2);
	return (1);
}

