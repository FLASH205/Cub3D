/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_phase_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:21:29 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/13 15:21:33 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	animation_phase(t_data *data)
{
	static int	n;
	
	if (n == 520)
	{
		data->current = (data->current + 1) % NUM_PIC;
		mlx_put_image_to_window(data->mlx_ptr, data->window, data->image->img, 0, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->window, data->frames[data->current].img, WIDTH / 14, HEIGHT / 7);
		// mlx_destroy_image(data->mlx_ptr, data->frames[data->current].img);
		n = 0;
	}
	n++;
	return (1);
}
