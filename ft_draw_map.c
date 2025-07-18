/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:11:18 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/18 19:57:03 by ybahmaz          ###   ########.fr       */
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
	int	color;

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
			{
				// if (i < -r / 2 && (j > -r / 2 && j < r / 2))
				// 	color = 0xff0000;
				// else
					color = 0x00ff33;
				ft_put_pixel(data->image, color, center_x + j, center_y + i);
			}
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
}
