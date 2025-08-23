/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:25:56 by mradouan          #+#    #+#             */
/*   Updated: 2025/08/19 12:42:38 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_safe_space(t_data *data, int i, int j)
{
	if (data->map[i][j + 1] && data->map[i][j + 1] != '1')
		return (1);
	if (j > 0 && data->map[i][j - 1] && data->map[i][j - 1] != '1')
		return (1);
	if (data->map[i + 1] && data->map[i + 1][j] && data->map[i + 1][j] != '1')
		return (1);
	if (i > 0 && data->map[i - 1] && data->map[i - 1][j]
		&& data->map[i - 1][j] != '1')
		return (1);
	return (0);
}

int	md_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

int	md_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	is_not_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (md_isdigit(str[i]) == 1)
			i++;
		else
			return (1);
	}
	return (0);
}

size_t	md_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
