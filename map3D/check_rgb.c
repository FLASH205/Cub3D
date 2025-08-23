/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:33:55 by mradouan          #+#    #+#             */
/*   Updated: 2025/08/23 09:56:52 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (!result)
		return (perror("Error\n"), NULL);
	return (result);
}

int	convert_to_hex(char *str)
{
	int		r_color;
	int		g_color;
	int		b_color;
	int		hex_num;
	char	**rgb;

	str = md_strtrim(str, "\n");
	if (!str)
		return (perror("Error\n"), 1);
	rgb = md_split(str, ',');
	if (!rgb)
		return (perror("Error\n"), 1);
	while (*rgb)
	{
		if (is_not_digit(*rgb) == 1)
			return (write(2, "Error\nnot digit\n", 16), 1);
		rgb++;
	}
	rgb -= 3;
	r_color = md_atoi(rgb[0]);
	g_color = md_atoi(rgb[1]);
	b_color = md_atoi(rgb[2]);
	if (r_color > 255 || g_color > 255 || b_color > 255)
		return (write(2, "Error\nThe number must be between 0-255\n", 39), 1);
	hex_num = (r_color << 16) | (g_color << 8) | b_color;
	return (hex_num);
}

int	check_first_digits(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
	if (!md_isdigit(line[*i]))
		return (write(2, "Error\nNeed digits\n", 18), 0);
	return (1);
}

int	check_commas(char *line, char *str, int i)
{
	int	comma;

	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		else if (md_isalpha(line[i]))
			return (free(str), write(2, "Error\nNeed digits\n", 18), 0);
		if (comma > 2)
			return (free(str), write(2,
					"Error\nSyntax error of rgb(0,0,0)\n", 33), 0);
		i++;
	}
	if (comma != 2)
		return (free(str), write(2,
				"Error\nSyntax error of rgb(0,0,0)\n", 33), 0);
	return (1);
}

int	parse_rgb(char *line)
{
	int		i;
	char	*str;
	int		hex;

	i = 1;
	str = NULL;
	if (!md_strncmp(line, "F", 1) || !md_strncmp(line, "C", 1))
	{
		if (!check_first_digits(line, &i))
			return (0);
		str = ft_strdup(line + i);
		if (!str)
			return (perror("Error\n"), 1);
		if (!check_commas(line, str, i))
			return (0);
	}
	hex = convert_to_hex(str);
	if (hex == 1)
		return (0);
	return (hex);
}
