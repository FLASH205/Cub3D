/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:11:18 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/24 17:54:42 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_image *image, int color, int x, int y)
{
	char	*addr;
	
	addr = image->addr;
	addr += image->l_size * y + x * image->bpp / 8;
	*(int *)addr = color;
}

void	setup_player(t_data *data, t_player *player)
{
	int	i;
	int	j;

	int	r = 10;
	int	center_x = player->pos.x;
	int	center_y = player->pos.y;

	i = -r;
	while (i <= r)
	{
		j = -r;
		while (j <= r)
		{
			if (i * i + j * j <= r * r)
				ft_put_pixel(data->image, 0x00ff33, center_x + j, center_y + i);
			j++;
		}
		i++;
	}
}



void	setup_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			ft_put_pixel(data->image, 0xffea8c, j + data->add_x, i + data->add_y);
			// mlx_pixel_put(data->mlx_ptr, data->window, j + data->add_x, i + data->add_y, 0xffea8c);
			j++;
		}
		i++;
	}
}

// static int	is_wall(float x, float y, char **map)
// {
// 	int map_x;
// 	int map_y;

// 	if (x < 0 || y < 0)
// 		return (1);
// 	map_x = (int)(x / SIZE);
// 	map_y = (int)(y / SIZE);
// 	if (map[map_y] && map[map_y][map_x] && map[map_y][map_x] == '1')
// 		return (1);
// 	return (0);
// }

// void	draw_ray(t_data *data, t_player *player, float angle)
// {
// 	float ray_x = player->pos.x;
// 	float ray_y = player->pos.y;
// 	float dx = cosf(angle) * RAY_STEP;
// 	float dy = sinf(angle) * RAY_STEP;

// 	if (is_wall(ray_x, ray_y, data->map))
// 			return ;
// 	ft_put_pixel(data->image, 0xff0000, ray_x, ray_y);
// 	while (1)
// 	{
// 		ray_x += dx;
// 		if (is_wall(ray_x, ray_y, data->map))
// 			return ;
// 		ray_y += dy;
// 		if (is_wall(ray_x, ray_y, data->map))
// 			return ;
// 		ft_put_pixel(data->image, 0xff0000, ray_x, ray_y);
// 	}
// }

// static void	get_horizontal(t_data *data, float angle, char **map, t_player *player)
// {
// 	float	y_step;
// 	float	x_step;
// 	float	hy;
// 	float	hx;

// 	// printf("H--------->position_x = %f\n", player->pos.x);
// 	// printf("H--------->position_y = %f\n", player->pos.y);
// 	hy = floorf(player->pos.y / SIZE) * SIZE;
// 	if (player->rayFaceDown)
// 		hy += SIZE;
// 	// printf("H--------->horizontal_y : %f\n", hy);
// 	hx = player->pos.x + (hy - player->pos.y) / tanf(angle);
// 	// printf("H--------->horizontal_x : %f\n", hx);
// 	y_step = SIZE;
// 	if (player->rayFaceUp)
// 		y_step *= -1;
// 	x_step = y_step / tanf(angle);
// 	if ((player->rayFaceLeft && x_step > 0) || (player->rayFaceRight && x_step < 0))
// 		x_step *= -1;
// 	while (1)
// 	{
// 		if (hx >= 0 && hy >= 0 && !is_wall(hx, hy, map))
// 		{
// 			hx += x_step;
// 			hy += y_step;
// 		}
// 		else if (hx >= 0 && hy >= 0 && is_wall(hx, hy, map))
// 			break ;
// 		else
// 			return ;
// 	}
// 	data->h_dist = sqrtf(powf(hx - player->pos.x, 2) + powf(hy - player->pos.y, 2));
// }

// static void	get_vertical(t_data *data, float angle, char **map, t_player *player)
// {
// 	float	vx;
// 	float	vy;
// 	float	y_step;
// 	float	x_step;

// 	printf("V--------->position_x = %f\n", player->pos.x);
// 	printf("V--------->position_y = %f\n", player->pos.y);
// 	vx = floorf(player->pos.x / SIZE) * SIZE;
// 	if (player->rayFaceRight)
// 		vx += SIZE;
// 	vy = (tanf(angle) * (vx - player->pos.x)) + player->pos.y;
// 	printf("angle = %f\n", angle);
// 	printf("tanf = %f\n", tanf(angle));
// 	printf("V--------->vertical_x : %f\n", vx);
// 	printf("V--------->vertical_y : %f\n", vy);
// 	printf("vx - player->pos.x = %f\n", vx - player->pos.x);
// 	x_step = SIZE;
// 	if (player->rayFaceLeft) 
// 		x_step *= -1;
// 	y_step = x_step * tanf(angle);
// 	if ((player->rayFaceUp && y_step > 0) || (player->rayFaceDown && y_step < 0))
// 		y_step *= -1;
// 	while (1)
// 	{
// 		if (vx < 0 || vy < 0)
// 			return ;
// 		if (is_wall(vx, vy, map))
// 			break ;
// 		vx += x_step;
// 		vy += y_step;
// 	}
// 	data->v_dist = sqrtf(powf(vx - player->pos.x, 2) + powf(vy - player->pos.y, 2));
// }

// static void	ft_raycaster(t_data *data, t_player *player, float angle)
// {
// 	reset_ray_face(data->player);
// 	player->rayFaceDown = (angle >= 0 && angle < PI);
// 	player->rayFaceUp = !player->rayFaceDown;
// 	player->rayFaceLeft = (angle > PI / 2 && angle < 3 * PI / 2);
// 	player->rayFaceRight = !player->rayFaceLeft;
// 	get_horizontal(data, angle, data->map, player);
// 	get_vertical(data, angle, data->map, player);
// }

float	normalize_angle(float angle)
{
	while (angle > PI * 2)
		angle -= 2 * PI;
	while (angle < 0)
		angle += PI * 2;
	return (angle);
}

void	ft_draw_map(char **map, t_data *data)
{
	int	i;
	int	j;
	
	data->add_y = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		data->add_x = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				setup_wall(data);
			j++;
			data->add_x += SIZE;
		}
		i++;
		data->add_y += SIZE;
	}
	setup_player(data, data->player);
	float angle = atan2f(data->player->dir.y, data->player->dir.x);
	angle = normalize_angle(angle);
	raycasting_phase(data, data->player, angle);
	// draw_ray(data, data->player, angle);
	// ft_raycaster(data, data->player, angle);
	// printf("horizontal_dis : %f\n", data->h_dist);
	// printf("vertical_dis : %f\n", data->v_dist);
}
