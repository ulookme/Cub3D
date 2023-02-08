/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:54:50 by charleshajj       #+#    #+#             */
/*   Updated: 2023/02/08 11:17:21 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int count_char(char *str, char c)
{
    int x;
    int count;

    x = 0;
    count = 0;
    while (str[x] != '\0' && ft_isprint(str[x]) != '\0')
    {
        if (str[x] == c)
            count++;
        x++;
    }
    return (count);
}

void    check_nb_player_map(t_game *game)
{
    
}