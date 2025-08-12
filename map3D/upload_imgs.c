/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:16:22 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/12 10:49:07 by mradouan         ###   ########.fr       */
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

char	*number_frames(void)
{
	char		*tmp;
	static int	i = 1;
	char		*num_str;
	char		*new_str;

	new_str = NULL;
	num_str = NULL;
	tmp = NULL;
	tmp = ft_strdup("Frames/frame_");
	if (!tmp)
		return (NULL);
	num_str = md_itoa(i);
	new_str = ft_strjoin(tmp, num_str);
	if (!new_str)
		return (free(num_str), perror("Error\n"), NULL);
	new_str = ft_strjoin(new_str, ".xpm");
	if (!new_str)
		return (free(new_str), perror("Error\n"), NULL);
	i++;
	free(num_str);
	return (new_str);
}

int	set_frames(t_data *data)
{
	int 	i;
	char	*img_name;

	i = 0;
	img_name = NULL;
	while (i < NUM_PIC)
	{
		img_name = number_frames();
		data->frames[i].img = mlx_xpm_file_to_image(data->mlx_ptr,
			img_name, &data->frames[i].width ,&data->frames[i].height);
		if (!data->frames[i].img) return (write(2, "Error\nFailed to load one or more .xpm files.\n", 45), 1);
		free(img_name);
		i++;
	}
	//!	All Of This Should Do It In While Loop____________________
	return (0);
}
