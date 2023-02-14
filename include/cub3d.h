/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:48 by chajjar           #+#    #+#             */
/*   Updated: 2023/02/14 05:09:45 by charleshajj      ###   ########.fr       */
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
# define PLAYER_COLOR 0x0000FF00
# define NORTH_COLOR 0x00FF0000
# define SOUTH_COLOR 0x0000FF00
# define EAST_COLOR 0x000000FF
# define WEST_COLOR 0x00FFFF00

# define ANGLE_OF_VIEW M_PI/4

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_vector_int
{
	int	x;
	int	y;
}	t_vector_int;

typedef struct s_img
{
	void			*ref;
	t_vector_int	size;
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}	t_img;

typedef struct s_player
{
	double		speed;
	double		apos;
	double		rotspeed;
	t_vector	pos;
}	t_player;

typedef struct s_map
{
	char		**tab;
	int			lines;
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

typedef struct s_parse
{
	int	flag_n;
	int	flag_s;
	int	flag_e;
	int	flag_w;
	int	flag_c;
	int	flag_f;
	int	read_map;
}	t_parse;

typedef struct s_game
{
	int		test_size;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*name_text[NB_TEXTURES];
	int		r_c;
	int		g_c;
	int		b_c;
	int		r_f;
	int		g_f;
	int		b_f;
	t_img	*ptr_texture;
	t_map	map;
	t_ray	r;
	t_img	img;
	t_img	img_text[NB_TEXTURES];
	double	*apos_game;
	int		rapport_player;
	t_parse	parse;
	char	*sprite[NB_ANIME][2];
	int		nb_sprite;
	int		dir_sprite;
	char	*read_str;
}	t_game;

typedef struct s_image
{
	t_game	game;
	t_game	legend;
	t_game	cube;
}	t_image;

void	check_file_map_parsing(t_game *game, int argc, char **argv);
void	parse_data_and_map2(t_game *game);
void	error_msg(char *msg);
int		check_color(int r, int g, int b);
int		parse_flag(t_game *game);
int		empty_line(char *line);
void	parse_text_and_color(char *path, t_game *cube, t_game *game);
void	parse_data_and_map(t_game *game, t_game *cube);
int		check_parameters_map(t_game *game);
int		find_char_map(char p, char *caracters);
int		check_map_char(t_game *game);
int		check_first_line(t_game *game);
int		check_last_line(t_game *game);
int		check_first_column(t_game *game);
int		check_last_column(t_game *game);
int		check_border_map(t_game *game);
int		c_space(char c);
int		check_zeros(t_game *game);
int		index_last_line(t_game *game);
void	init_angle_player(t_game *game);
void	init_var_player(t_game *game);
void	init_player_position(t_game *game, char *line, int y);
int		find_player(char p, char *caracters);
int 	count_char(char *str, char c);
void	check_nb_player(t_game *game);
void	init_game(t_game *game);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	draw_player(t_game *game, int posx, int posy, int color);
void	draw_player_p(t_game *game, int x, int y);
void	draw_square(t_game *game, int posx, int posy, int color);
void	img_pix_put(t_game *game, int x, int y, int color);
int		reprint_pos(t_game *game);
int		print_map(t_game *game);
void	init_legend(t_game *game, t_game *legend);
void	draw_circle_bis(t_game *image, int r, int color);
void	draw_circle(t_game *image, int r, int color);
int		anim_legend(t_game *legend);
void	init_cube(t_game *game, t_game *cube);
int		calc_texture(double x_map, int i, t_image *images, int face);
void	init_text(t_game *cube);
int		input(int key, t_image *images);
int		input_2(t_image *images);
int		ft_close(t_image *image);
int		move_test(int x, int y, t_image *images);
int		movements_mouse(int button, int x, int y, t_image *images);
void	update(t_image *image, int key);
void	move_player(t_game *game, double nb, double alpha);
void	anim_direction(t_game *legend, int key);
int		anim_cub3d(t_image *images);
void	ft_init_var_3d_1(t_game *cube, int x);
void	ft_calc_dist(t_image *images, t_game *cube, char *texture_hit);
void	ft_choice_texture(t_image *images, t_game *cube, char *texture_hit);
void	ft_clear_logo_direction(t_image *images, t_game *cube);

#endif
