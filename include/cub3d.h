/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:48 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/08 12:37:49 by charleshajj      ###   ########.fr       */
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

# define DEFINITION_TEXTURES 600
# define NB_TEXTURES 11

# define WALL '1'
# define FLOOR '0'
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

# define FILL_CHAR '-'
# define ANGLE_OF_VIE M_PI/4


typedef struct s_player
{
	double		speed;
	double		apos;
	double		x_pos;
	double		y_pos;
	double		rot;
}	t_player;

typedef struct s_map
{
	char		**tab;
	int			raws;
	int			columns;
	int			nb_player;
	int			move;
	int			hit_wall;
	t_player	p;

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
	double		*apos_game;
	int			rapport_player;
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
void    init_pos_player(t_game *game);
void	init_player(t_game *game);
int		find_player(char p, char *caracters);
void    init_player_position(t_game *game,char *line, int y);
int		count_char(char *str, char c);
void	check_nb_player_map(t_game *game);

#endif
