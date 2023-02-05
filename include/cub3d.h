/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:48 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/05 21:41:55 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include <stdio.h>
# include <time.h>

# define DEFINITION_TEXTURE 600
# define NB_TEXTURES 11

# define WALL '1'
# define FLOOR '0'
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

# define FILL_CHAR '-'


typedef struct s_player
{
	double		x_pos;
	double		y_pos;
	double		rot;
}	t_player;

typedef struct s_map
{
	char	**tab;
	int		raws;
	int		columns;

}	t_map;

typedef struct s_parsing
{
	int	flag_n;
	int	flag_s;
	int	flag_e;
	int	flag_w;
	int	flag_c;
	int	flag_f;
	int	reading_map;

}	t_parsing;

typedef struct s_game
{
	int			textsize;
	void		*mlx_ptr;
	void		*wind_ptr;
	char		*name_text[NB_TEXTURES];
	int			r_c;
	int			g_c;
	int			b_c;
	int			r_f;
	int			g_f;
	int			b_f;
	t_player	player;
	t_parsing	parse;
	char		*reading;
	t_map		map;
}	t_game;

typedef struct s_im
{
	t_game	cube;
	t_game	legende;
	t_game	game;
}	t_im;

void	check_file_map_parsing(t_game *game, int argc, char **argv);
int		find_start_pos(const char *str, t_game *cube);
void	fill_algorithm(int x, int y, char **region);
void	parse_map_line(t_game *game);
int		parse_map_line2(t_game *game);
void	check_error(t_game *game);
void	error_msg(char *msg);
int		check_color(int r, int g, int b);
int		parse_flag(t_game *game);
int		is_empty_line(char *line);
int		find_cell_color(char *path, t_game *cube);
int		find_floor_color(char *path, t_game *cube);
void	parse_text_color(char *path, t_game *cube, t_game *game);
void	parsing_map(t_game *game, t_game *cube);
int		find_char_map(char p, char *caracters);
int		check_map_char(t_game *game);
int		index_last_raw(t_game *game);
int		c_space(char c);
int		check_zero(t_game *game);
int		check_parametre_map(t_game *game);
#endif
