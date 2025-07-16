/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:38:30 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/07/16 18:27:55 by ybahmaz          ###   ########.fr       */
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
	(void)data;
	if (key == ESC)
		(ft_clean_all(data), exit(0));
	return (1);
}

void	get_positions(t_player *player, char c, int i, int j)
{
	player->pos.x = j;
	player->pos.y = i;
	if (c == 'N')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (c == 'S')
	{
		player->dir.x = 0;
		player->dir.y = -1;
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

int	main(void)
{
	t_data	data;
	char	*map[] = {
		"11111111111111",
		"100000W0000001",
		"10000000000001",
		"10000000000001",
		"10001000000001",
		"10001000000001",
		"11111111111111",
		NULL};
	data.player = malloc(sizeof(t_player));
	if (!data.player)
		return (1);
	data.w_map = 0;
	data.h_map = 0;
	init_map(map, &data);
	printf("position of player is: x = %.1f ; y = %.1f\n", data.player->pos.x, data.player->pos.y);
	printf("direction of player is: dx = %.1f; dy = %.1f\n", data.player->dir.x, data.player->dir.y);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.window = mlx_new_window(data.mlx_ptr, data.w_map * 64, data.h_map * 64, "Cub3d");
	if (!data.window)
		return (ft_clean_all(&data), 1);
	mlx_key_hook(data.window, ft_click_keys, &data);
	mlx_hook(data.window, 17, 0, click_cross, &data);
	return (mlx_loop(data.mlx_ptr), ft_clean_all(&data), 0);
}
