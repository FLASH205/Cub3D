/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:32:05 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/16 18:02:14 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1
# endif

# define ESC 53

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
	t_player	*player;
}	t_data;


char	*get_next_line(int fd);
char	*ft_strchr(char *str);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
void	ft_clean_all(t_data *data);

#endif