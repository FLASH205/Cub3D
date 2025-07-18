/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:39:34 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/18 19:55:46 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_memset(void *str, int c, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		((char *)str)[i] = c;
		i++;
	}
	
}

void	rotate_player(t_player *player, double angle)
{
	float	old_dir_x;

	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(angle) - player->dir.y * sin(angle);
	player->dir.y = old_dir_x * sin(angle) + player->dir.y * cos(angle);
}


// int is_wall(float x, float y, char **map)
// {
// 	int map_x = (int)(x / SIZE);
// 	int map_y = (int)(y / SIZE);

// 	if (map[map_y][map_x] == '1')
// 		return (1);
// 	return (0);
// }

// int is_collision(float new_x, float new_y, char **map)
// {
// 	return (
// 		is_wall(new_x + P_SPEED, new_y, map) ||
// 		is_wall(new_x - P_SPEED, new_y, map) ||
// 		is_wall(new_x, new_y + P_SPEED, map) ||
// 		is_wall(new_x, new_y - P_SPEED, map)
// 	);
// }

int	move_player(int key, t_data *data)
{
	t_player	*player;
	// float		new_x;
	// float		new_y;

	player = data->player;
	// new_x = player->pos.x;
	// new_y = player->pos.y;
	if (key == UP)
	{
		player->pos.x += player->dir.x * P_SPEED;
		player->pos.y += player->dir.y * P_SPEED;
	}
	else if (key == DOWN)
	{
		player->pos.x -= player->dir.x * P_SPEED;
		player->pos.y -= player->dir.y * P_SPEED;
	}
	else if (key == RIGHT || key == A_RIGHT)
	{
		rotate_player(player, ROT_SPEED);
		// player->pos.x += P_SPEED;
	}
	else if (key == LEFT || key == A_LEFT)
	{
		rotate_player(player, -ROT_SPEED);
		// player->pos.x -= P_SPEED;
	}
	// if (!is_collision(new_x, player->pos.y, data->map))
	// 	player->pos.x = new_x;
	// if (!is_collision(player->pos.x, new_y, data->map))
	// 	player->pos.y = new_y;
	ft_memset(data->image->addr, 0, data->h_map * SIZE * data->w_map * SIZE * data->image->bpp / 8);
	ft_draw_map(data->map, data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->image->img, 0, 0);
	return (1);
}
