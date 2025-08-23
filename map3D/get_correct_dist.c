/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_correct_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:14:57 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/19 12:46:13 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	vertical_dist(int i, float angle,
	t_player *player, t_data *data)
{
	float	x;
	float	y;

	data->is_horizontal[i] = 0;
	x = player->pos.x + cosf(angle) * data->v_dist;
	y = player->pos.y + sinf(angle) * data->v_dist;
	if (player->rayFaceRight)
	{
		x += 0.001;
		y += 0.001;
	}
	if (player->rayFaceLeft)
		data->tex[i] = &data->we_map;
	else
		data->tex[i] = &data->ea_map;
	if (data->map[(int)y / SIZE][(int)x / SIZE] == 'D')
		data->tex[i] = &data->door;
	return (data->v_dist);
}

float	get_correct_distance(t_data *data, t_player *player, int i, float angle)
{
	float	x;
	float	y;

	if (data->h_dist < data->v_dist)
	{
		data->is_horizontal[i] = 1;
		x = player->pos.x + cosf(angle) * data->h_dist;
		y = player->pos.y + sinf(angle) * data->h_dist;
		if (player->rayFaceDown)
		{
			x += 0.001;
			y += 0.001;
		}
		if (player->rayFaceUp)
			data->tex[i] = &data->no_map;
		else
			data->tex[i] = &data->so_map;
		if (data->map[(int)y / SIZE][(int)x / SIZE] == 'D')
			data->tex[i] = &data->door;
		return (data->h_dist);
	}
	return (vertical_dist(i, angle, player, data));
}
