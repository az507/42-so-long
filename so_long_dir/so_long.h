/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:25:43 by achak             #+#    #+#             */
/*   Updated: 2024/03/14 20:30:51 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/libft.h"

# define GRID_WIDTH 40
# define GRID_HEIGHT 40 

# define MLX_ERROR 1

# define MIN_WIDTH 3
# define MIN_HEIGHT 3

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define YELLOW_PIXEL 0xFFFF33
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

/*
typedef struct s_xpm
{
	void	*xpm_img;
	int		xpm_width;
	int		xpm_height;
}	t_xpm;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	colour;
}	t_rect;
*/

typedef struct s_map
{
	char	**map_arr;
	int		width;
	int		height;
	int		collectible;
	int		*sp;
	int		exit_pos0;
	int		exit_pos1;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img[1];
	t_map	map;
	int		window_width;
	int		window_height;
}	t_data;

char	**validate_map(int ac, char **av, t_map *map);

char	**check_and_assign_map(char **map_arr, t_map *map);
char	**parse_map(char *file, t_map *map);

void	free_arr(char **arr);
char	*strjoin_and_frees1(char *s1, char *s2);
void	print_error(char *error_msg, char **map_arr);
int		ft_strncmp_last(char *s1, char *s2, size_t n);

int		count_map_width(char *map_width);
int		count_map_height(char **map_arr);
int		check_map_dimensions(char **map_arr);
void	check_map_shape_and_size(char **map_arr);

void	check_map_components(char **map_arr);
void	check_if_special_component(char component, int *exit, int *collectible,
			int *start);
void	check_no_of_special_components(char **map_arr, t_map *map);

void	check_map_width(char **map_arr, int index);
void	check_map_height(char **map_arr, int index);
void	check_map_walls(char **map_arr);

void	copy_s1_to_s2(char *s1, char *s2);
char	**copy_map(char **map_arr);
int		*find_position_of_component(char **map_arr, char component);
void	check_valid_path(char **map_arr, t_map *map);

void	fill(char **map_arr, int x, int y, char to_fill);
void	flood_fill(char **map_arr, int *sp, char to_fill);
int		check_if_filled(char **map_cpy, char special1, char special2);

///////////////////

void	start_game(t_map map);

//int		handle_no_input(void *data);
void	exit_success(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_cross(t_data *data);
void	set_up_hooks(t_data *data);

void	img_pixel_put(t_img *img, int x, int y, int colour);
int		find_map_component(t_data *data, char component);
void	render_background(t_data *data, int index, int colour);
int		render(t_data *data);
void	init_img_ptr(t_data *data, int index, float width, float height);
//void	prepare_images(t_data *data);

void	render_wall(t_data *data, int j, int i, int colour);
void	render_block(t_data *data, int j, int i, int colour);
//void	render_circle(t_data *data, int j, int i, int colour);
void	render_map_component(t_data *data, char c, int colour);

//void	move_player_position(t_data *data);
//void	remove_collectible(t_data *data);
int		check_infront(t_data *data, char infront, int flag);
void	change_previous_map_component(int keysym, t_data *data, char change_to);
void	change_map_arr_components(int keysym, t_data *data);
int		move_player_on_map(int keysym, t_data *data);
void	handle_movement(int keysym, t_data *data);

#endif
