/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:32:05 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/17 18:31:17 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1
# endif

# define ESC 53
# define P_SPEED 8	//*	player speed
# define ROT_SPEED 0.05	//*	rotate speed
# define SIZE 64
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define A_LEFT 123
# define A_RIGHT 124

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;	//*	bit_per_pixel
	int		l_size;
}	t_image;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_player
{
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
	int			add_x;
	int			add_y;
	t_player	*player;
	t_image		*image;
}	t_data;


char	*get_next_line(int fd);
char	*ft_strchr(char *str);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
void	ft_clean_all(t_data *data);
void	ft_draw_map(char **map, t_data *data);
void	setup_player(t_data *data, int x, int y);
int		move_player(int key, t_data *data);
#endif