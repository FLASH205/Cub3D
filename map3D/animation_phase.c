/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_phase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:21:32 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/11 19:14:35 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	animation_phase(t_data *data)
{
	static int	n;
	
	if (n == 480)
	{
		data->current = (data->current + 1) % NUM_PIC;
		mlx_put_image_to_window(data->mlx_ptr, data->window, data->image->img, 0, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->window, data->frames[data->current].img, WIDTH / 4, HEIGHT / 1.8);
		// mlx_destroy_image(data->mlx_ptr, data->frames[data->current].img);
		n = 0;
	}
	n++;
	return (1);
}
