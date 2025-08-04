/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:16:22 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/04 13:27:08 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_imgs(t_data *data)
{
	int w;
	int h;
	data->no_map.img = mlx_xpm_file_to_image(data->mlx_ptr, data->no_map.value, &w, &h);
	data->so_map.img = mlx_xpm_file_to_image(data->mlx_ptr, data->so_map.value, &w, &h);
	data->we_map.img = mlx_xpm_file_to_image(data->mlx_ptr, data->we_map.value, &w, &h);
	data->ea_map.img = mlx_xpm_file_to_image(data->mlx_ptr, data->ea_map.value, &w, &h);
	if (!data->no_map.img || !data->so_map.img || !data->ea_map.img || !data->we_map.img)
		return (write(2, "Error\ntextures not found\n", 25), 1);
	return (0);
}
