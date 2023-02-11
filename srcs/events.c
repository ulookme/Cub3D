/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:12:07 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/11 23:26:04 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	event_close(void *param)
{
	write(1, param, ft_strlen(param));
	exit(0);
}

int	event_key(t_game *game)
{
	(void) game;
	return (0);
}