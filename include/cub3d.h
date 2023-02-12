/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:48 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/12 22:03:55 by charleshajj      ###   ########.fr       */
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


#  define TOUCH_A 0
#  define TOUCH_W 13
#  define TOUCH_S 1
#  define TOUCH_D 2
#  define TOUCH_RIGHT 124
#  define TOUCH_LEFT 123
#  define TOUCH_UP 126
#  define TOUCH_DOWN 125
#  define TOUCH_ESC 53
#  define DEGREE_X1 120
#  define DEGREE_Y1 258
#  define DEGREE_X2 146
#  define DEGREE_Y2 291


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

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dir_x;
	double	dir_y;
	double	planex;
	double	planey;
	double	dirx;
	double	diry;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	mapx;
	double	mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	stepx;
	double	stepy;
	int		hit;
	int		side;
	int		index;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		x;
}	t_ray;

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
	t_ray		r;
	double		*apos_game;
	int			rapport_player;
	char		*sprite[NB_ANIME][2];
	int			nb_sprite;
	int			dir_sprite;
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
void	ft_init_var_3d_1(t_game *cube, int x);
void	calc_dist(t_im *images, t_game *cube, char *texture_hit);
void	ft_choice_texture(t_im *images, t_game *cube, char *texture_hit);
void	ft_clear_logo_direction(t_im *images, t_game *cube);
int		ft_calc_texture(double x_map, int i, t_im *images, int face);
int		anim_cub3d(t_im *images);
void	update(t_im *image, int key);
void	move_player(t_game *game, double nb, double alpha);
void	anim_direction(t_game *legende, int key);
int		input_2(t_im *images);
int		input(int key, t_im *images);
void	init_legend(t_game *game, t_game *legend);
void	draw_circle_bis(t_game *image, int r, int color);
void	draw_circle(t_game *image, int r, int color);
int		anim_legend(t_game *legend);
int		ft_close(t_im *image);
void	init_cube(t_game *game, t_game *cube);

#endif
