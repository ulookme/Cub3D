/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:48 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/11 23:25:06 by charleshajj      ###   ########.fr       */
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
# include "../mlx/mlx.h"

# define DEFINITION_TEXTURES 600
# define NB_TEXTURES 11
# define NB_ANIME 2  
# define IMAGE_X 900
# define IMAGE_Y 900
# define CUBE_X 600
# define CUBE_Y 600
# define LEGENDE_X 300
# define LEGENDE_Y 600

# define WALL '1'
# define FLOOR '0'
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

# define SKY_COLOR 0x000000FF
# define WALL_COLOR 0x006C767C
# define FLOOR_COLOR 0x008FB5D1
# define PLAYER_COLOR 0x001093D9
# define NORTH_COLOR 0x00FF0000
# define SOUTH_COLOR 0x0000FF00
# define EAST_COLOR 0x000000FF
# define WEST_COLOR 0x00FFFF00

# define FILL_CHAR '-'
# define ANGLE_OF_VIE M_PI/4

typedef struct s_vector_int
{
	int	x;
	int	y;
}	t_vector_int;

typedef struct s_img
{
	void			*ref;
	t_vector_int	size;
	char			*addr;
	int				bpp;
	void			*mlx_img;
	int				raw_len;
	int				endian;
}	t_img;

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
	t_img		*ptr_texture;
	t_img		img;
	t_img		img_text[NB_TEXTURES];
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
void	ft_test_size_map(t_game *game);
void	init_game(t_game *game);
int		test_size_map2(t_game *game);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	img_pix_put(t_game *game, int x, int y, int color);
void	draw_player(t_game *game, int posx, int posy, int color);
void	draw_square(t_game *game, int posx, int posy, int color);
void	draw_player_p(t_game *game, int x, int y);
int		reprint_pos(t_game *game);
int		print_map(t_game *game);
void	init_legend(t_game *game, t_game *legende);

int		event_close(void *param);
int		event_key(t_game *game);

#endif
