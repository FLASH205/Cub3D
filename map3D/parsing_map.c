/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:02:38 by mradouan          #+#    #+#             */
/*   Updated: 2025/08/01 10:18:28 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	name_file_check(char *file_name)
{
	int i;
    int j;
	char *cube;

	cube = ".cub";
	i = 0;
    j = 4;
	while (file_name[i])
		i++;
	while (--j >= 0)
	{
		if (file_name[i - 1] != cube[j])
			return (write(2, "Error\nEnter the right file name <*.cub>\n", 40), 1);
        i--;
	}
	return (0);
}

int count_width_height(t_data *data)
{
	int	fd;
	int	counter;
	int max_width;
	int len_line;
	char *line;
	
	counter = 0;
	max_width = 0;
	len_line = 0;
	fd = open("map.cub", O_RDONLY, 0644);
	if (fd == -1)
		return (perror("Error\n"), 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!md_strncmp(line, "NO", 2) || !md_strncmp(line, "SO", 2) || !md_strncmp(line, "WE", 2)
				|| !md_strncmp(line, "EA", 2) || !md_strncmp(line, "F", 1) || !md_strncmp(line, "C", 1))
			line = get_next_line(fd);
		else if ((md_strchr(line, '1') || md_strchr(line, '0') || md_strchr(line, 'N')
			|| md_strchr(line, 'S') || md_strchr(line, 'E') || md_strchr(line, 'W')))
		{
			counter++;
			len_line = ft_strlen(md_strtrim(line, "\n"));
			if (len_line >= max_width)
				max_width = len_line;
		}
		free(line);
	}
	data->h_map = counter;
	data->w_map = max_width;
	close(fd);
	return(0);  
}

char	*parse_direction(char *line)
{
	int i;
	char *result;
	
	i = 2;
	if (!md_strncmp(line, "NO", 2) || !md_strncmp(line, "SO", 2)
		|| !md_strncmp(line, "WE", 2) || !md_strncmp(line, "EA", 2))
	{
		while (line[i])
		{
			if (md_isdigit(line[i]) || md_isalpha(line[i]))
				break ;
			i++;
		}
	}
	result = ft_strdup(line + i);
	return (result);
}

int	convert_to_hex(char *str)
{
	int	r_color;
	int	g_color;
	int	b_color;
	int	hex_num;
	char **rgb;

	rgb = md_split(str, ',');
	r_color = md_atoi(rgb[0]);
	g_color = md_atoi(rgb[1]);
	b_color = md_atoi(rgb[2]);
	if (r_color > 255 || g_color > 255 || b_color > 255)
		return (write(2, "Error\nThe number must be between 0-255\n", 39), 1);
	hex_num = (r_color << 16) | (g_color << 8) | b_color;
	return (hex_num);
}

int	parse_rgb(char *line)
{
	int comma;
	char	*str;
	int len_color;
	int	hex;
	int i;

	comma = 0;
	len_color = 0;
	i = 1;
	str = NULL;
	if (!md_strncmp(line, "F", 1) || !md_strncmp(line, "C", 1))
	{
		while (line[i] == ' ')
			i++;
		if (!md_isdigit(line[i]))
			return (write(2, "Error\nNeed digits\n", 18), 0);
		str = ft_strdup(line + i);
		while (md_isdigit(line[i]) || md_isalpha(line[i]))
		{
			if (md_isalpha(line[i]))
				return (free(str), write(2, "Error\nNeed digits\n", 18), 0);
			i++;
			len_color++;
		}
		while (line[i])
		{
			if ((line[i] == ',' && md_isdigit(line[i - 1]) && md_isdigit(line[i + 1])) || (line[i] == ',' && line[i + 1] == '\0'))
				comma++;
			if (comma > 2)
				return (free(str), write(2, "Error\nSyntax error of rgb(0,0,0)\n", 33), 0);
			i++;
			len_color++;
		}
		if (comma != 2)
			return (free(str), write(2, "Error\nSyntax error of rgb(0,0,0)\n", 33), 0);
	}
	hex = convert_to_hex(str);
	if (hex == 1)
		return(0);
	return (hex);
}


int	load_file(t_data *data, int fd)
{
	char *line;
	int	order;
	int i;

	if (count_width_height(data) == 1)
		return (1);
	data->map = malloc((data->h_map + 1) * sizeof(char *));
	if (!data->map)
		return(perror("Error\n"), 1);
	data->map[0] = NULL;
	i = 0;
	order = 1;
	while (1)
	{
        line = get_next_line(fd);
        if (!line)
            break ;
		if (md_strncmp(line, "NO", 2) == 0)
			data->no_map.value = parse_direction(line);
		else if (md_strncmp(line, "SO", 2) == 0)
			data->so_map.value = parse_direction(line);
		else if (md_strncmp(line, "WE", 2) == 0)
			data->we_map.value = parse_direction(line);
		else if (md_strncmp(line, "EA", 2) == 0)
			data->ea_map.value = parse_direction(line);
		else if (md_strncmp(line, "F", 1) == 0)
			data->f_color = parse_rgb(line);
		else if (md_strncmp(line, "C", 1) == 0)
			data->c_color = parse_rgb(line);
		else if (md_strchr(line, '1') || md_strchr(line, '0') || md_strchr(line, 'N') || md_strchr(line, 'S') || md_strchr(line, 'E') || md_strchr(line, 'W'))
		{
			if (order != 7)
				return (free(line), write(2, "Error\nOrder Problem !\n", 22), 1);
			data->map[i] = malloc(ft_strlen(line));
			data->map[i] = md_strtrim(line, "\n");
			i++;
		}
		if (line[0] != '\n' && (!data->map[0]))
			order++;
		free(line);
	}
	data->map[i] = NULL;
	if (!data->no_map.value || !data->so_map.value || !data->we_map.value || !data->ea_map.value || !data->f_color || !data->c_color || !data->map[0])
		return (free_str(data->map), write(2, "Error\nNeed more categories\n", 27), 1);
    return (0);
}

int	check_deff_co(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'N' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'S' && data->map[i][j] != 'W'
				&& data->map[i][j] != ' ')
				return (0);
			j++;	
		}
		i++;
	}
	return (1);
}

int	check_component(t_data *data)
{
	int i;
	int is_wall;
	int is_player;
	int is_free_space;

	i = 0;
	is_player = 0;
	is_wall = 0;
	is_free_space = 0;
	while (data->map[i])
	{
		if (md_strchr(data->map[i], '1'))
			is_wall = 1;
		if (md_strchr(data->map[i], '0') == 1)
			is_free_space = 1;
		if (md_strchr(data->map[i], 'S') || md_strchr(data->map[i], 'E') || md_strchr(data->map[i], 'W') || md_strchr(data->map[i], 'N'))
			is_player = 1;
		i++;
	}
	if (!is_player || !is_free_space || !is_wall || !check_deff_co(data))
		return (write(2, "Error\nYou Must set all components require\n", 42), 1);
	return (0);
}

int	pasre_map(t_data *data)
{
	if (check_component(data) == 1)
		return (1);
	// if (check_if_closed(data) == 1)
	// 	return (1);
	return (0);
}

int	parsing_file(t_data *data, char *file_name)
{
	int	fd;

	if (name_file_check(file_name) == 1)
		return (1);
	fd = open(file_name, O_RDONLY, 0644);
	if (fd == -1)
		return (perror("Error\n"), 1);
	if (load_file(data, fd))
		return (1);
	if (pasre_map(data) == 1)
		return (1);
	return (0);
}
