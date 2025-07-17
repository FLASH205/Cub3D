/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:39:34 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/17 18:17:43 by ybahmaz          ###   ########.fr       */
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
	printf("dir_x : %.2f\tdir_y : %.2f\n", player->dir.x, player->dir.y);
	player->dir.x = player->dir.x * cos(angle) - player->dir.y * sin(angle);
	player->dir.y = old_dir_x * sin(angle) + player->dir.y * cos(angle);
}

int	move_player(int key, t_data *data)
{
	t_player	*player;

	player = data->player;
	if (key == UP)
		data->player->pos.y -= P_SPEED;
	else if (key == DOWN)
		data->player->pos.y += P_SPEED;
	else if (key == RIGHT || key == A_RIGHT)
	{
		rotate_player(player, -ROT_SPEED);
		// data->player->pos.x += P_SPEED;
	}
	else if (key == LEFT || key == A_LEFT)
	{
		rotate_player(player, ROT_SPEED);
		// data->player->pos.x -= P_SPEED;
	}
	ft_memset(data->image->addr, 0, data->h_map * SIZE * data->w_map * SIZE * data->image->bpp / 8);
	ft_draw_map(data->map, data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->image->img, 0, 0);
	return (1);
}
