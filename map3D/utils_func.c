/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:15:22 by mradouan          #+#    #+#             */
/*   Updated: 2025/08/12 10:47:34 by mradouan         ###   ########.fr       */
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
	if (i > 0 && data->map[i - 1] && data->map[i - 1][j] && data->map[i - 1][j] != '1')
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

int	if_str(char const c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*md_strtrim(char *s1, char *set)
{
	char		*trim_s;
	size_t		len_s;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (if_str(((char )*s1), set) == 1)
			s1++;
		else
			break ;
	}
	len_s = ft_strlen(s1);
	while (len_s != 0)
	{
		if (if_str(s1[len_s - 1], set) == 1)
			len_s--;
		else
			break ;
	}
	trim_s = (char *)malloc((len_s + 1) * sizeof(char));
	if (!trim_s)
		return (NULL);
	md_strlcpy(trim_s, (char *)s1, len_s + 1);
	return (trim_s);
}

int	md_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	md_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (1);
		s++;
	}
	if ((unsigned char)c == '\0')
		return (0);
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_puthex(unsigned long num, char *base)
{
	int		count;

	count = 0;
	if (num >= 16)
	{
		count += ft_puthex(num / 16, base);
		count += ft_puthex(num % 16, base);
	}
	else
		count += ft_putchar(base[num]);
	return (count);
}

long	md_atoi(const char *str)
{
	int		i;
	int		sign;
	long	t;

	i = 0;
	sign = 1;
	t = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		t = t * 10 + (str[i] - 48);
		if (t > 2147483648)
			return (2147483648);
		i++;
	}
	return (t * sign);
}

int	get_length(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*md_itoa(int n)
{
	char	*result;
	int		len;
	long	num;
	int		is_negative;

	num = n;
	len = get_length(n);
	result = malloc((len * sizeof(char)) + 1);
	if (!result)
		return (perror("Error\n"), NULL);
	result[len] = '\0';
	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		result[0] = '-';
		num = -num;
	}
	while (--len >= 0)
	{
		if (is_negative && len == 0)
			break ;
		result[len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
