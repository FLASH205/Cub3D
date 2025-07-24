/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_phase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:18:17 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/24 19:29:12 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall(int x, int y, t_data *data)
{
	int	x_map;
	int	y_map;

	if (x < 0 || y < 0 || x > data->w_map * SIZE || y > data->h_map * SIZE)
		return (1);
	x_map = (int)(x / SIZE);
	y_map = (int)(y / SIZE);
	if (data->map[y_map] && data->map[y_map][x_map] && data->map[y_map][x_map] == '1')
		return (1);
	return (0);
}

static void	get_horizontal(t_data *data, float angle, t_player *player)
{
	float	x_h;
	float	y_h;
	float	x_step;
	float	y_step;

	y_h = floorf(player->pos.y / SIZE) * SIZE;
	// if (player->rayFaceDown)
	// 	y_h += SIZE;
	x_h = (y_h - player->pos.y) / tanf(angle) + player->pos.x;
	y_step = SIZE;
	
	if (player->rayFaceUp)
		y_step *= -1;
	x_step = y_step / tanf(angle);
	if (player->rayFaceLeft && x_step > 0)
		x_step *= -1;
	if (player->rayFaceRight && x_step < 0)
		x_step *= -1;
	while (1)
	{
		if (is_wall(x_h, y_h, data))
			break ;
		x_h += x_step;
		y_h += y_step;
	}
	data->h_dist = sqrtf(powf(x_h - player->pos.x, 2) + powf(y_h - player->pos.y, 2));
}

static void	get_vertical(t_data *data, float angle, t_player *player)
{
	float	x_v;
	float	y_v;
	float	x_step;
	float	y_step;

	x_v = floorf(player->pos.x / SIZE) * SIZE;
	// if (player->rayFaceRight)
	// 	x_v += SIZE;
	y_v = (tanf(angle) * (x_v - player->pos.x)) + player->pos.y;
	x_step = SIZE;
	if (player->rayFaceLeft)
		x_step *= -1;
	y_step = x_step * tanf(angle);
	if (player->rayFaceUp && y_step > 0)
		y_step *= -1;
	if (player->rayFaceDown && y_step < 0)
		y_step *= -1;
	while (1)
	{
		if (is_wall(x_v, y_v, data))
			break ;
		x_v += x_step;
		y_v += y_step;
	}
	data->v_dist = sqrtf(powf(x_v - player->pos.x, 2) + powf(y_v - player->pos.y, 2));
}

void	raycasting_phase(t_data *data, t_player *player, float angle)
{
	// float	d_x;
	// float	d_y;
	
	reset_ray_face(player);
	player->rayFaceDown = (angle >= 0 && angle < PI);
	player->rayFaceUp = !player->rayFaceDown;
	player->rayFaceLeft = (angle > PI / 2 && angle < 3 * PI / 2);
	player->rayFaceRight = !player->rayFaceLeft;
	get_horizontal(data, angle, player);
	get_vertical(data, angle, player);
	printf("horizontal_dis : %f\n", data->h_dist);
	printf("vertical_dis : %f\n", data->v_dist);
	int i = 0;
	float d_x, d_y;
	float dx = cosf(angle); // اتجاه الشعاع فـ X
	float dy = sinf(angle); // اتجاه الشعاع فـ Y

	while (i < data->h_dist) // المسافة بين اللاعب والجدار
	{
		d_x = data->player->pos.x + dx * i;
		d_y = data->player->pos.y + dy * i;
		ft_put_pixel(data->image, 0xff0000, d_x, d_y);
		i++;
	}

	
}
