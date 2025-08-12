/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:32:05 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/12 15:54:23 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
// # include "/home/rd_md_haker/Documents/mlx/mlx.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1
# endif

# define NUM_PIC 86
# define PI 3.14159265
# define PLAYER_RADIUS 6
# define ESC 53
# define P_SPEED 25	//*	player speed
# define ROT_SPEED 0.1	//*	rotate speed
# define SIZE 32
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define A_LEFT 123
# define A_RIGHT 124
# define FOV PI / 3
# define RAY_STEP 1
# define WIDTH 1280
# define HEIGHT 768

typedef struct s_image
{
	void	*img;
	char	*addr;
	char	*value;
	int		bpp;	//*	bit_per_pixel
	int		l_size;
	int		width;
	int		height;
}	t_image;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_player
{
	int			rayFaceUp;
	int			rayFaceDown;
	int			rayFaceRight;
	int			rayFaceLeft;
	t_vector	pos;
	t_vector	dir;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*window;
	char		**map;
	int			w_map;
	int			h_map;
	int			*arr_width;
	t_image		no_map;
	t_image		so_map;
	t_image		we_map;
	t_image		ea_map;
	t_image		*tex[WIDTH];
	int			f_color;
	int			c_color;
	int			add_x;
	int			add_y;
	int			current;
	float		hit_x[WIDTH]; // horizontal
	float		hit_y[WIDTH]; // vertical
	float		h_dist;
	float		v_dist;
	t_player	*player;
	t_image		*image;
	// int			is_vertical[WIDTH];
	int			is_horizontal[WIDTH];
	float		dist_rays[WIDTH];
	// int			color[WIDTH];
	t_image		frames[NUM_PIC];
}	t_data;

char	*get_next_line(int fd);
char	*ft_strchr(char *str);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
void	ft_clean_all(t_data *data);
void	ft_draw_map(t_data *data);
void	reset_ray_face(t_player *player);
// void	setup_player(t_data *data, t_player *player);
int		handle_keys(int key, t_data *data);
void	v2_raycast(t_data *data, t_player *player, float angle);
void	ft_put_pixel(t_image *image, int color, int x, int y);
float	normalize_angle(float angle);
int		set_frames(t_data *data);
int		animation_phase(t_data *data);

//                         MOHA FUNCTIONS

int		parsing_file(t_data *data, char *file_name);
char	*parse_direction(char *line);
int		is_safe_space(t_data *data, int i, int j);
int		parse_rgb(char *line);
int		set_imgs(t_data *data);
char	**md_split(char const *s, char c);
int		md_strncmp(const char *s1, const char *s2, size_t n);
size_t	md_strlcpy(char *dst, const char *src, size_t dstsize);
char	*md_strtrim(char *s1, char *set);
int		md_strchr(const char *s, int c);
int		md_isdigit(int c);
int		md_isalpha(int c);
long	md_atoi(const char *str);
char	*md_itoa(int n);
int		ft_puthex(unsigned long num, char *base);
void	free_str(char **str);

#endif