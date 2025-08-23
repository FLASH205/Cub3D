/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:00:14 by mradouan          #+#    #+#             */
/*   Updated: 2025/08/23 10:55:08 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			ft_put_pixel(data->image, color, x + j, y + i);
			j++;
		}
		i++;
	}
}

// void	draw_player_mini(t_data *data)
// {

// }


void	draw_mini_map(t_data *data)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < data->h_map)
	{
		j = 0;
		while (j < data->arr_width[i])
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			if (data->map[i][j] == '1')
				draw_square(data, x, y, 0x00FFAA);
			else if (data->map[i][j] == 'D')
				draw_square(data, x, y, 0x996633);
			else
				draw_square(data, x, y, 0x111111);
			j++;
		}
		i++;
	}
	// draw_player_mini(data);
}

