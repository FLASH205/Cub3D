/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:19:46 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/04 18:03:27 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clean_all(t_data *data)
{
	if (data->window)
		mlx_destroy_window(data->mlx_ptr, data->window);
	if (data->image->img)
		mlx_destroy_image(data->mlx_ptr, data->image->img);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->no_map.img)
		(free(data->no_map.value), mlx_destroy_image(data->mlx_ptr, data->no_map.img));
	if (data->so_map.img)
		(free(data->so_map.value), mlx_destroy_image(data->mlx_ptr, data->so_map.img));
	if (data->we_map.img)
		(free(data->we_map.value), mlx_destroy_image(data->mlx_ptr, data->we_map.img));
	if (data->ea_map.img)
		(free(data->ea_map.value), mlx_destroy_image(data->mlx_ptr, data->ea_map.img));
}
