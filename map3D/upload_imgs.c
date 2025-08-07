/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:16:22 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/07 09:42:01 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_imgs(t_data *data)
{
	int	g;

	data->no_map.img = mlx_xpm_file_to_image(data->mlx_ptr, data->no_map.value,
			&data->no_map.width, &data->no_map.height);
	data->so_map.img = mlx_xpm_file_to_image(data->mlx_ptr, data->so_map.value,
			&data->so_map.width, &data->so_map.height);
	data->we_map.img = mlx_xpm_file_to_image(data->mlx_ptr, data->we_map.value,
			&data->we_map.width, &data->we_map.height);
	data->ea_map.img = mlx_xpm_file_to_image(data->mlx_ptr, data->ea_map.value,
			&data->ea_map.width, &data->ea_map.height);
	if (!data->no_map.img || !data->so_map.img
		|| !data->ea_map.img || !data->we_map.img)
		return (write(2, "Error\ntextures not found\n", 25), 1);
	data->no_map.addr = mlx_get_data_addr(data->no_map.img,
			&data->no_map.bpp, &data->no_map.l_size, &g);
	data->so_map.addr = mlx_get_data_addr(data->so_map.img,
			&data->so_map.bpp, &data->so_map.l_size, &g);
	data->we_map.addr = mlx_get_data_addr(data->we_map.img,
			&data->we_map.bpp, &data->we_map.l_size, &g);
	data->ea_map.addr = mlx_get_data_addr(data->ea_map.img,
			&data->ea_map.bpp, &data->ea_map.l_size, &g);
	return (0);
}
