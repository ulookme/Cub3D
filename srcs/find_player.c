/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:54:13 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/14 03:37:48 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	find_player(char p, char *caracters)
{
	int	i;

	i = 0;
	while (caracters[i] != '\0')
	{
		if (p == caracters[i])
			return (1);
	i++;
	}
	return (0);
}