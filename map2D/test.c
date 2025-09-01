/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:42:29 by mradouan          #+#    #+#             */
/*   Updated: 2025/07/30 21:28:34 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



unsigned int rgb_to_hex_int(int r, int g, int b) {
    // Clamp each value between 0 and 255
    if (r < 0) r = 0; if (r > 255) r = 255;
    if (g < 0) g = 0; if (g > 255) g = 255;
    if (b < 0) b = 0; if (b > 255) b = 255;

    // Shift red 16 bits, green 8 bits, blue stays
    return (r << 16) | (g << 8) | b;
}

// int main()
// {
//     t_data *data;
//     data = malloc(sizeof(t_data));
// 	load_file(data);
// }
int main() {
	int r =  0x0069, g = 99, b = 71;
	unsigned int hex = rgb_to_hex_int(r, g, b);

	printf("Hex value: %x\n", hex); // Output: 0xFF6347

	return 0;
}