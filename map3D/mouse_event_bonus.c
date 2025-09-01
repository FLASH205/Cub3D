/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:43:46 by mradouan          #+#    #+#             */
/*   Updated: 2025/09/01 11:25:27 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player_mouse(t_data *data, double angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->player->dir.x;
	data->player->dir.x = data->player->dir.x * cosf(angle)
		- data->player->dir.y * sinf(angle);
	data->player->dir.y = old_dir_x * sinf(angle)
		+ data->player->dir.y * cosf(angle);
	old_plane_x = data->player->plane.x;
	data->player->plane.x = data->player->plane.x * cosf(angle)
		- data->player->plane.y * sinf(angle);
	data->player->plane.y = old_plane_x * sinf(angle)
		+ data->player->plane.y * cosf(angle);
}

int	handel_mouse(int x, int y, t_data *data)
{
	static int	last_x = -1;

	(void)y;
	if (last_x == -1)
		last_x = x;
	if (x > last_x)
		rotate_player_mouse(data, 0.05);
	else if (x < last_x)
		rotate_player_mouse(data, -0.05);
	last_x = x;
	return (0);
}
