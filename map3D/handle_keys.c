/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:39:34 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/12 09:58:14 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *player, float angle)
{
	float	old_dir_x;

	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cosf(angle) - player->dir.y * sinf(angle);
	player->dir.y = old_dir_x * sinf(angle) + player->dir.y * cosf(angle);
}

int	is_collision(float x, float y, char **map)
{
	int	mx;
	int	my;

	//* Check left_________________
	mx = (int)((x - PLAYER_RADIUS) / SIZE);
	my = (int)(y / SIZE);
	if (map[my][mx] == '1')
		return (1);
	//* Check right_________________
	mx = (int)((x + PLAYER_RADIUS) / SIZE);
	my = (int)(y / SIZE);
	if (map[my][mx] == '1')
		return (1);
	//* Check up_________________
	mx = (int)(x / SIZE);
	my = (int)((y - PLAYER_RADIUS) / SIZE);
	if (map[my][mx] == '1')
		return (1);
	//* Check down_________________
	mx = (int)(x / SIZE);
	my = (int)((y + PLAYER_RADIUS) / SIZE);
	if (map[my][mx] == '1')
		return (1);
	//* Top-left_________________
	mx = (int)((x - PLAYER_RADIUS) / SIZE);
	my = (int)((y - PLAYER_RADIUS) / SIZE);
	if (map[my][mx] == '1')
		return (1);
	//* Top-right_________________
	mx = (int)((x + PLAYER_RADIUS) / SIZE);
	my = (int)((y - PLAYER_RADIUS) / SIZE);
	if (map[my][mx] == '1')
		return (1);
	//* Bottom-left_________________
	mx = (int)((x - PLAYER_RADIUS) / SIZE);
	my = (int)((y + PLAYER_RADIUS) / SIZE);
	if (map[my][mx] == '1')
		return (1);
	//* Bottom-right_________________
	mx = (int)((x + PLAYER_RADIUS) / SIZE);
	my = (int)((y + PLAYER_RADIUS) / SIZE);
	if (map[my][mx] == '1')
		return (1);

	return (0);
}

int	handle_keys(int key, t_data *data)
{
	t_player	*player;
	float		new_x;
	float		new_y;

	player = data->player;
	new_x = player->pos.x;
	new_y = player->pos.y;
	if (key == ESC)
		(ft_clean_all(data), exit(0));
	if (key == UP)
	{
		new_x = player->pos.x + player->dir.x * P_SPEED;
		new_y = player->pos.y + player->dir.y * P_SPEED;
	}
	else if (key == DOWN)
	{
		new_x = player->pos.x - player->dir.x * P_SPEED;
		new_y = player->pos.y - player->dir.y * P_SPEED;
	}
	else if (key == RIGHT)
	{
		new_x = player->pos.x + -player->dir.y * P_SPEED;
		new_y = player->pos.y + player->dir.x * P_SPEED;
	}
	else if (key == LEFT)
	{
		new_x = player->pos.x + player->dir.y * P_SPEED;
		new_y = player->pos.y + -player->dir.x * P_SPEED;
	}
	else if (key == A_RIGHT)
		rotate_player(player, ROT_SPEED);
	else if (key == A_LEFT)
		rotate_player(player, -ROT_SPEED);
	//~ check collision before moving (Bonus)____________
	if (!is_collision(new_x, player->pos.y, data->map))
		player->pos.x = new_x;
	if (!is_collision(player->pos.x, new_y, data->map))
		player->pos.y = new_y;

	//* redraw___________________
	ft_draw_map(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->window, data->image->img, 0, 0);
	return (1);
}
