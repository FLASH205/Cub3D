/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:02:38 by mradouan          #+#    #+#             */
/*   Updated: 2025/08/17 09:47:19 by mradouan         ###   ########.fr       */
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
	int		i;
	char	*trimmed;
	char	*result;

	i = 2;

	while (line[i] == ' ' || line[i] == '\t')
		i++;
	trimmed = md_strtrim(line + i, " \t\n");
	if (!trimmed)
		return (NULL);
	result = ft_strdup(trimmed);
	free(trimmed);
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
			if ((line[i] == ',' && md_isdigit(line[i - 1]) && md_isdigit(line[i + 1])) || (line[i] == ',' && line[i + 1] == '\n'))
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
		else if (md_strchr(line, '1') || md_strchr(line, '0') || md_strchr(line, 'N') || md_strchr(line, 'S') || md_strchr(line, 'E') || md_strchr(line, 'W') || md_strchr(line, 'D'))
		{
			if (order != 7)
				return (free(line), write(2, "Error\nOrder Problem !\n", 22), 1);
			data->map[i] = md_strtrim(line, "\n");
			if (!data->map[i])
			{
				while (--i >= 0)
					free(data->map[i]);
				return (free(data->map) ,1);
			}
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
				&& data->map[i][j] != ' ' && data->map[i][j] != 'D')
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

	i = 0;
	is_player = 0;
	is_wall = 0;
	while (data->map[i])
	{
		if (md_strchr(data->map[i], '1'))
			is_wall = 1;
		if (md_strchr(data->map[i], 'S') || md_strchr(data->map[i], 'E') || md_strchr(data->map[i], 'W') || md_strchr(data->map[i], 'N'))
			is_player = 1;
		i++;
	}
	if (!is_player || !is_wall || !check_deff_co(data))
		return (write(2, "Error\nYou Must set all components require\n", 42), 1);
	return (0);
}

int	check_one_last(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1' && data->map[0][i] != ' ')
			return (write(2, "Error\nMap must be closed\n", 25), 1);
		i++;
	}
	i = 0;
	while (data->map[data->h_map - 1][i])
	{
		if (data->map[data->h_map - 1][i] != '1'
			&& data->map[data->h_map - 1][i] != ' ')
			return (write(2, "Error\nMap must be closed\n", 25), 1);
		i++;
	}
	return (0);
}

int	check_space_close(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			while (data->map[i][j] && data->map[i][j] == ' ')
				j++;
			while (data->map[i][j] && data->map[i][j] != ' ')
				j++;
			if (data->map[i][j] == ' ' && is_safe_space(data, i, j))
				return (write(2, "Error\nMap must be closed\n", 25), 1);
			if (data->map[i][j])
				j++;
		}
		i++;
	}
	return (0);
}

int	check_zero_null(t_data *data)
{
	int i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((data->map[i][j] == '0') && 
				((ft_strlen(data->map[i - 1]) < ft_strlen(data->map[i]) && data->map[i - 1][j] == '\0') ||
				(ft_strlen(data->map[i + 1]) < ft_strlen(data->map[i]) && data->map[i + 1][j] == '\0')))
				return (write(2, "Error\nMap must be closed\n", 25), 1);
			if ((data->map[i][j] == '0') &&
				((data->map[i + 1] && data->map[i + 1][j] == ' ') ||
				(data->map[i - 1] && data->map[i - 1][j] == ' ')))
				return (write(2, "Error\nMap must be closed\n", 25), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_closed(t_data *data)
{
	int	i;
	int	len_rows;

	i = 0;
	if (check_one_last(data) == 1)
		return (1);
	while (data->map[i])
	{
		len_rows = ft_strlen(data->map[i]);
		if (data->map[i][0] != '1' && data->map[i][0] != ' ')
			return (write(2, "Error\nMap must be closed\n", 25), 1);
		if (data->map[i][0] == '\n')
			return (write(2, "Error\nMap has a newline\n", 24), 1);
		if (data->map[i][len_rows - 1] != '1')
			return (write(2, "Error\nMap must be closed\n", 25), 1);
		i++;
	}
	if (check_space_close(data) == 1)
		return (1);
	if (check_zero_null(data) == 1)
		return (1);
	return (0);
}

int is_only_spaces(char *s)
{
	int	i;

	i = 0;
    if (!s || s[i] == '\0')
        return (1);
    while (s[i])
    {
        if (s[i] != ' ' && s[i] != '\t'
			&& s[i] != '\n' && s[i] != '\r')
            return (0);
        i++;
    }
    return 1;
}

int	check_new_line(char *filename)
{
	char *line;
	int	fd;

	fd = open(filename, O_RDONLY, 0644);
	if (fd == -1)
		return (perror("Error\n"), 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line[0] == '1')
			break ;
		free(line);
	}
	while (1)
	{
		if (!line)
			break ;
		if (is_only_spaces(line) == 1)
			return (free(line), write(2, "Error\nline is empty\n", 20), 1);
		if (line[0] == '\n')
			return (write(2, "Error\nMap has a newline\n", 24), 1);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), free(line), 0);
}

int	check_door(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'D' && (data->map[i][j + 1] != 'D' || ))	//! should complete that!!___________
				return (write(2, "Error\nDoor must be into 1 (1D1)\n", 32), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	pasre_map(t_data *data, char *filename)
{
	if (check_component(data) == 1)
		return (1);
	if (check_if_closed(data) == 1)
		return (1);
	if (check_new_line(filename) == 1)
		return (1);
	if (check_door(data) == 1)
		return (1);
	return (0);
}

int	claim_wd_line(t_data *data)
{
	int	i;

	i = 0;
	data->arr_width = malloc((data->h_map + 1) * (sizeof(int)));
	if (!data->arr_width)
		return (1);
	while (i < data->h_map)
	{
		data->arr_width[i] = ft_strlen(data->map[i]);
		i++;
	}
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
	if (pasre_map(data, file_name) == 1)
		return (1);
	if (claim_wd_line(data))
		return (1);
	return (0);
}
