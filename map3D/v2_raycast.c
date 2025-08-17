/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:02:17 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/17 09:50:21 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall(int x, int y, t_data *data)
{
	int	x_map;
	int	y_map;
	int	x_offset;
	int	y_offset;

	if (x < 0 || y < 0 || y >= data->h_map * SIZE
		|| x >= data->arr_width[y / SIZE] * SIZE)
		return (1);
	x_map = (int)(x / SIZE);
	y_map = (int)(y / SIZE);
	if (data->map[y_map] && data->map[y_map][x_map]
		&& (data->map[y_map][x_map] == '1' || data->map[y_map][x_map] == 'D'))
		return (1);
	if (data->player->rayFaceLeft)
		x_offset = 1;
	else
		x_offset = -1;
	if (data->player->rayFaceUp)
		y_offset = 1;
	else
		y_offset = -1;
	if ((data->map[y_map + y_offset][x_map] == '1' || data->map[y_map + y_offset][x_map] == 'D')
		&& (data->map[y_map][x_map + x_offset] == '1' || data->map[y_map][x_map + x_offset] == 'D'))
		return (1);
	return (0);
}

void	get_horizontal_dist(t_data *data, float angle, t_player *player, int i)
{
	float	x_h;
	float	y_h;
	float	x_step;
	float	y_step;

	y_h = floorf(player->pos.y / SIZE) * SIZE;
	if (player->rayFaceDown)
		y_h += SIZE;
	else
		y_h -= 0.001f;
	x_h = (y_h - player->pos.y) / tanf(angle) + player->pos.x;
	y_step = SIZE;
	if (player->rayFaceUp)
		y_step *= -1;
	x_step = y_step / tanf(angle);
	if (player->rayFaceLeft && x_step > 0)
		x_step *= -1;
	while (1)
	{
		if (is_wall(x_h, y_h, data))
			break ;
		x_h += x_step;
		y_h += y_step;
	}
	data->hit_x[i] = x_h;
	data->h_dist = sqrtf(powf(x_h - player->pos.x, 2)
			+ powf(y_h - player->pos.y, 2));
}

void	get_vertical_dist(t_data *data, float angle, t_player *player, int i)
{
	float	x_v;
	float	y_v;
	float	x_step;
	float	y_step;

	x_v = floorf(player->pos.x / SIZE) * SIZE;
	if (player->rayFaceRight)
		x_v += SIZE;
	else
		x_v -= 0.001f;
	y_v = player->pos.y + (tanf(angle) * (x_v - player->pos.x));
	x_step = SIZE;
	if (player->rayFaceLeft)
		x_step *= -1;
	y_step = tanf(angle) * x_step;
	if (player->rayFaceUp && y_step > 0)
		y_step *= -1;
	while (1)
	{
		if (is_wall(x_v, y_v, data))
			break ;
		x_v += x_step;
		y_v += y_step;
	}
	data->hit_y[i] = y_v;
	data->v_dist = sqrtf(powf(x_v - player->pos.x, 2)
			+ powf(y_v - player->pos.y, 2));
}

float	get_correct_distance(t_data *data, t_player *player, int i, float angle)
{
	int x;
	int y;

	if (data->h_dist < data->v_dist)
	{
		data->is_horizontal[i] = 1;
		x = player->pos.x + cosf(angle) * data->h_dist;
		y = player->pos.y + sinf(angle) * data->h_dist;
		if (player->rayFaceDown)
		{
			x += 1;
			y += 1;
		}
		if (data->map[y / SIZE][x / SIZE] == 'D')
			data->tex[i] = &data->door;
		else if (player->rayFaceUp)
			data->tex[i] = &data->no_map;
		else
			data->tex[i] = &data->so_map;
		return (data->h_dist);
	}
	else
	{
		data->is_horizontal[i] = 0;
		x = player->pos.x + cosf(angle) * data->v_dist;
		y = player->pos.y + sinf(angle) * data->v_dist;
		if (data->map[y / SIZE][x / SIZE] == 'D')
			data->tex[i] = &data->door;
		else if (player->rayFaceLeft)
			data->tex[i] = &data->we_map;
		else
			data->tex[i] = &data->ea_map;
		return (data->v_dist);
	}
}

void	v2_raycast(t_data *data, t_player *player, float angle)
{
	int		i;
	float	ray_angle;
	float	correct_dist;

	i = 0;
	while (i < WIDTH)
	{
		ray_angle = normalize_angle(angle + i * FOV / WIDTH);
		reset_ray_face(player);
		player->rayFaceDown = (ray_angle > 0 && ray_angle < PI);
		player->rayFaceUp = !player->rayFaceDown;
		player->rayFaceLeft = (ray_angle >= PI / 2 && ray_angle <= 3 * PI / 2);
		player->rayFaceRight = !player->rayFaceLeft;
		get_horizontal_dist(data, ray_angle, player, i);
		get_vertical_dist(data, ray_angle, player, i);
		correct_dist = get_correct_distance(data, data->player, i, ray_angle);
		data->dist_rays[i] = cosf(ray_angle
				- atan2f(player->dir.y, player->dir.x)) * correct_dist;
		i++;
	}
}
