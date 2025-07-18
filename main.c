/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:38:30 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/18 19:54:57 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	click_cross(t_data *data)
{
	ft_clean_all(data);
	exit(0);
}

int	ft_click_keys(int key, t_data *data)
{
	if (key == ESC)
		(ft_clean_all(data), exit(0));
	return (1);
}

void	get_positions(t_player *player, char c, int i, int j)
{
	player->pos.x = j * SIZE + SIZE / 2;
	player->pos.y = i * SIZE + SIZE / 2;
	if (c == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (c == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (c == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	else if (c == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
}

void	init_map(char **map, t_data *data)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (map[i])
	{
		data->w_map = ft_strlen(map[i]);
		j = 0;
		while (map[i][j] && !n)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				(get_positions(data->player, map[i][j], i, j), n = 1);
			j++;
		}
		i++;
	}
	data->h_map = i;
}

int	create_new_img(t_data *data, t_image *image)
{
	int	g;

	image->img =  mlx_new_image(data->mlx_ptr, data->w_map * SIZE, data->h_map * SIZE);
	if (!image->img)
		return (0);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->l_size, &g);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	//^		 char	*addr;
	//^		 int	w = 32;
	//^		 int	x = 2;
	//^		 int y = 3;
	//^		 addr + w * y + x + bpp;
	//^		 *(int *)addr = i;
	char	*map[] = {
		"11111111111111111111111111111111",
		"10000000000000000000000000000001",
		"10000000000000000000000000000001",
		"10000000010000000000000000000001",
		"10001000010000001111100000000001",
		"10001000000000001000100000000001",
		"100010000000000010N0100010000001",
		"10000000000000001000100001000001",
		"11111111111111111111111111111111",
		NULL
	};
	if (ac != 2)
		return (write(2, "Should be two arguments\n", 24), 1);
	data.player = (t_player []){{}};
	data.image = (t_image []){{}};
	data.w_map = 0;
	data.h_map = 0;
	init_map(map, &data);
	data.map = malloc(sizeof(char *) * (data.h_map + 1));
	if (!data.map)
		return (1);
	if (!ft_read_file(&data, av[1]))
		return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.window = mlx_new_window(data.mlx_ptr, data.w_map * SIZE, data.h_map * SIZE, "Cub3d");
	if (!data.window)
		return (ft_clean_all(&data), 1);
	if (!create_new_img(&data, data.image))
		return (ft_clean_all(&data), 1);
	ft_draw_map(data.map, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.window, data.image->img, 0, 0);
	mlx_key_hook(data.window, ft_click_keys, &data);
	mlx_hook(data.window, 2, 1L<<0, move_player, &data);
	mlx_hook(data.window, 17, 0, click_cross, &data);
	return (mlx_loop(data.mlx_ptr), ft_clean_all(&data), 0);
}
