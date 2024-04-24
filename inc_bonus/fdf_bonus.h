/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:22:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/17 15:29:41 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

// Window and image macros
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define TITLE "FDF"
# define IMAGE_WIDTH WINDOW_WIDTH
# define IMAGE_HEIGHT WINDOW_HEIGHT
# define EXTENSION ".fdf"
# define BITS_IN_BYTE 8

# define MENU_WIDTH 380
# define MENU_HEIGHT IMAGE_HEIGHT
# define MENU_COLOR 0x002C2C2C
# define STR_COLOR 0x00FFFFFF
# define TAB_SIZE 40
# define NEW_LINE 24

// Map macros
# define Z_POS_IDX 0
# define COLOR_IDX 1
# define MAX_Z_DIFF 32
# define COLOR_BASE_LENGTH 16

// Color macros
# define BACKGROUND_COLOR 0x000F0F0F
# define BOTTOM_COLOR 0x002E86C1
# define TOP_COLOR 0x00F1C40F 
# define MAX_VALUE_COLOR_COMPONENT 255
# define ALPHA_BIT 24
# define RED_BIT 16
# define GREEN_BIT 8
# define BLUE_BIT 0

// Projection macros
# define X_AXIS 0
# define Y_AXIS 1
# define Z_AXIS 2

// Zoom macros
# define ZOOM_FACTOR 1.1
# define MIN_ZOOM 0.005
# define MAX_ZOOM 540.0

// Rotation macros
# define IS_ROTATING_XY 1
# define IS_ROTATING_Z 2
# define SENS 360

// Z factor macros
# define MIN_Z_FACTOR 0.1
# define MAX_Z_FACTOR 10000.0
# define Z_FACTOR_CHANGE 1.5

// Key codes
# define ESCAPE 53
# define P_KEY 35
# define T_KEY 17
# define R_KEY 15
# define PLUS_KEY 24
# define MINUS_KEY 27
# define H_KEY 4
# define LEFT_BUTTON 1
# define RIGHT_BUTTON 2
# define MOUSE_WHEEL 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// Event codes
# define KEY_PRESS 2
# define BTN_PRESS 4
# define BTN_RELSE 5
# define MSE_MOVE 6
# define CLOSE_WINDOW 17

// Mask codes
# define KEY_P_MASK 1L
# define BTN_P_MASK 4L
# define BTN_R_MASK 8L
# define MSE_M_MASK 64L

// Error macros
# define ERROR_PREFIX_LEN 7

// Includes
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

// Structs
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_edge
{
	double	x;
	double	y;
	double	start_x;
	double	start_y;
	double	final_x;
	double	final_y;
	int		start_color;
	int		final_color;
}	t_edge;

typedef struct s_img_data
{
	void	*image;
	char	*first_pixel;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_mlx
{
	void		*ptr;
	void		*window;
	t_img_data	*img_data;
}	t_mlx;

typedef struct s_state
{
	t_mlx	*mlx;
	char	*map_path;
	int		num_lines;
	int		line_size;
	int		scale;
	double	x_offset;
	double	y_offset;
	int		biggest_z;
	int		smallest_z;
	int		translate_start_x;
	int		translate_start_y;
	int		rotation_started;
	double	rotation_x;
	double	rotation_y;
	double	rotation_z;
	int		is_translating;
	int		is_rotating;
	double	zoom;
	double	z_factor;
	double	rotations_angles[3];
	int		is_menu_hidden;
	t_point	**map;
	t_point	**backup_map;
}	t_state;

// State helpers
int		init_state(char *map, t_state *state);
void	free_state(t_state *state);

// Init map helpers
int		is_every_map_line_equal(t_state *state, char **raw_map);
int		calculate_string_array_length(char **array);
void	free_point_map(t_point **map);
int		parse_color(char *num);

// Parse map helpers
void	free_string_matrix(char **map);
char	**read_raw_map(t_state *state);
t_point	**parse_map(t_state *state, char **raw_map);

// Map operations
void	space_point(t_state *state, t_point **map, int x_pos, int y_pos);
void	center_point(t_state *state, t_point **map, int x_pos, int y_pos);
void	rotate_point(t_state *state, t_point **map, int x_pos, int y_pos);
void	calc_color_point(t_state *state, t_point **map, int x_pos, int y_pos);
void	restore_map(t_state *state);

// Print menu
void	paint_menu_layout(t_state *state);
void	write_menu_hud(t_state *state);

// Colors helpers
void	color_pixel(t_img_data *img_data, int x, int y, int color);
int		create_color_argb(int alpha, int red, int green, int blue);
int		get_color_component(int color, int component);
int		calculate_pixel_color(t_state *state, t_point *point);
int		calculate_edge_color(t_edge *edge);

// Rotations helpers
void	rotate_x_axis(t_point *point, double angle);
void	rotate_y_axis(t_point *point, double angle);
void	rotate_z_axis(t_point *point, double angle);

// Projections
void	isometric_view(t_state *state);
void	parallel_view(t_state *state);
void	top_view(t_state *state);

// Paint background
void	paint_background(t_state *state);

// Paint map
void	paint_map(t_state *state);

// Paint map helpers
int		calculate_scale(t_state *state);
int		calculate_z_maxmin_diff(t_state *state);
double	calculate_z_factor(t_state *state);
void	configure_map(t_state *state, t_point **map);
void	add_config_to_map(t_state *state, t_point **map,
			void (*conf) (t_state *state, t_point **map, int x_pos, int y_pos));

// Paint edges helpers
double	calc_edge_color_factor(t_edge *edge);
int		calc_new_comp(int color0, int color1, int mask, double factor);
void	paint_edge(t_state *state, t_edge *edge);

// Math functions
double	module(int x, int y);

// Hooks
int		close_window(t_state *state);
int		handle_mousemove(int x, int y, t_state *state);
int		handle_btnrelse(int mouse_code, int x, int y, t_state *state);
int		handle_btnpress(int mouse_code, int x, int y, t_state *state);
int		handle_keypress(int key_code, t_state *state);

// Hooks helpers
void	update_image(t_state *state);
void	reset_map(t_state *state);
void	aplicate_zoom(t_state *state, int mouse_code, int mouse_x, int mouse_y);
void	translate_map(t_state *state, int mouse_x, int mouse_y);
void	rotate_map(t_state *state, int mouse_x, int mouse_y);

// Error handlers
void	handle_error(t_state *state, char *error);

#endif
