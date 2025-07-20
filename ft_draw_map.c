/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:11:18 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/20 22:21:02 by ybahmaz          ###   ########.fr       */
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

static int	is_wall(float x, float y, char **map)
{
	int map_x = (int)(x / SIZE);
	int map_y = (int)(y / SIZE);

	if (map[map_y] && map[map_y][map_x] && map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	draw_ray(t_data *data, t_player *player, float angle)
{
	float ray_x = player->pos.x;
	float ray_y = player->pos.y;
	float dx = cos(angle) * RAY_STEP;
	float dy = sin(angle) * RAY_STEP;

	while (!is_wall(ray_x, ray_y, data->map))
	{
		ft_put_pixel(data->image, 0xff0000, ray_x, ray_y);
		ray_x += dx;
		ray_y += dy;
	}
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
	float angle = atan2(data->player->dir.y, data->player->dir.x);
	draw_ray(data, data->player, angle);
}
