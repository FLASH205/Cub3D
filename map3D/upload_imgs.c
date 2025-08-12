/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:16:22 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/08/12 09:59:48 by ybahmaz          ###   ########.fr       */
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

int	set_frames(t_data *data)
{
	data->frames[0].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_1.xpm", &data->frames[0].width ,&data->frames[0].height);
	data->frames[1].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_2.xpm", &data->frames[1].width ,&data->frames[1].height);
	data->frames[2].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_3.xpm", &data->frames[2].width ,&data->frames[2].height);
	data->frames[3].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_4.xpm", &data->frames[3].width ,&data->frames[3].height);
	data->frames[4].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_5.xpm", &data->frames[4].width ,&data->frames[4].height);
	data->frames[5].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_6.xpm", &data->frames[5].width ,&data->frames[5].height);
	data->frames[6].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_7.xpm", &data->frames[6].width ,&data->frames[6].height);
	data->frames[7].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_8.xpm", &data->frames[7].width ,&data->frames[7].height);
	data->frames[8].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_9.xpm", &data->frames[8].width ,&data->frames[8].height);
	data->frames[9].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_10.xpm", &data->frames[9].width ,&data->frames[9].height);
	data->frames[10].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_11.xpm", &data->frames[10].width ,&data->frames[10].height);
	data->frames[11].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_12.xpm", &data->frames[11].width ,&data->frames[11].height);
	data->frames[12].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_13.xpm", &data->frames[12].width ,&data->frames[12].height);
	data->frames[13].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_14.xpm", &data->frames[13].width ,&data->frames[13].height);
	data->frames[14].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_15.xpm", &data->frames[14].width ,&data->frames[14].height);
	data->frames[15].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_16.xpm", &data->frames[15].width ,&data->frames[15].height);
	data->frames[16].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_17.xpm", &data->frames[16].width ,&data->frames[16].height);
	data->frames[17].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_18.xpm", &data->frames[17].width ,&data->frames[17].height);
	data->frames[18].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_19.xpm", &data->frames[18].width ,&data->frames[18].height);
	data->frames[19].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_20.xpm", &data->frames[19].width ,&data->frames[19].height);
	data->frames[20].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_21.xpm", &data->frames[20].width ,&data->frames[20].height);
	data->frames[21].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_22.xpm", &data->frames[21].width ,&data->frames[21].height);
	data->frames[22].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_23.xpm", &data->frames[22].width ,&data->frames[22].height);
	data->frames[23].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_24.xpm", &data->frames[23].width ,&data->frames[23].height);
	data->frames[24].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_25.xpm", &data->frames[24].width ,&data->frames[24].height);
	data->frames[25].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_26.xpm", &data->frames[25].width ,&data->frames[25].height);
	data->frames[26].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_27.xpm", &data->frames[26].width ,&data->frames[26].height);
	data->frames[27].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_28.xpm", &data->frames[27].width ,&data->frames[27].height);
	data->frames[28].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_29.xpm", &data->frames[28].width ,&data->frames[28].height);
	data->frames[29].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_30.xpm", &data->frames[29].width ,&data->frames[29].height);
	data->frames[30].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_31.xpm", &data->frames[30].width ,&data->frames[30].height);
	data->frames[31].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_32.xpm", &data->frames[31].width ,&data->frames[31].height);
	data->frames[32].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_33.xpm", &data->frames[32].width ,&data->frames[32].height);
	data->frames[33].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_34.xpm", &data->frames[33].width ,&data->frames[33].height);
	data->frames[34].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_35.xpm", &data->frames[34].width ,&data->frames[34].height);
	data->frames[35].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_36.xpm", &data->frames[35].width ,&data->frames[35].height);
	data->frames[36].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_37.xpm", &data->frames[36].width ,&data->frames[36].height);
	data->frames[37].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_38.xpm", &data->frames[37].width ,&data->frames[37].height);
	data->frames[38].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_39.xpm", &data->frames[38].width ,&data->frames[38].height);
	data->frames[39].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_40.xpm", &data->frames[39].width ,&data->frames[39].height);
	data->frames[40].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_41.xpm", &data->frames[40].width ,&data->frames[40].height);
	data->frames[41].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_42.xpm", &data->frames[41].width ,&data->frames[41].height);
	data->frames[42].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_43.xpm", &data->frames[42].width ,&data->frames[42].height);
	data->frames[43].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_44.xpm", &data->frames[43].width ,&data->frames[43].height);
	data->frames[44].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_45.xpm", &data->frames[44].width ,&data->frames[44].height);
	data->frames[45].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_46.xpm", &data->frames[45].width ,&data->frames[45].height);
	data->frames[46].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_47.xpm", &data->frames[46].width ,&data->frames[46].height);
	data->frames[47].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_48.xpm", &data->frames[47].width ,&data->frames[47].height);
	data->frames[48].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_49.xpm", &data->frames[48].width ,&data->frames[48].height);
	data->frames[49].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_50.xpm", &data->frames[49].width ,&data->frames[49].height);
	data->frames[50].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_51.xpm", &data->frames[50].width ,&data->frames[50].height);
	data->frames[51].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_52.xpm", &data->frames[51].width ,&data->frames[51].height);
	data->frames[52].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_53.xpm", &data->frames[52].width ,&data->frames[52].height);
	data->frames[53].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_54.xpm", &data->frames[53].width ,&data->frames[53].height);
	data->frames[54].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_55.xpm", &data->frames[54].width ,&data->frames[54].height);
	data->frames[55].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_56.xpm", &data->frames[55].width ,&data->frames[55].height);
	data->frames[56].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_57.xpm", &data->frames[56].width ,&data->frames[56].height);
	data->frames[57].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_58.xpm", &data->frames[57].width ,&data->frames[57].height);
	data->frames[58].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_59.xpm", &data->frames[58].width ,&data->frames[58].height);
	data->frames[59].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_60.xpm", &data->frames[59].width ,&data->frames[59].height);
	data->frames[60].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_61.xpm", &data->frames[60].width ,&data->frames[60].height);
	data->frames[61].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_62.xpm", &data->frames[61].width ,&data->frames[61].height);
	data->frames[62].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_63.xpm", &data->frames[62].width ,&data->frames[62].height);
	data->frames[63].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_64.xpm", &data->frames[63].width ,&data->frames[63].height);
	data->frames[64].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_65.xpm", &data->frames[64].width ,&data->frames[64].height);
	data->frames[65].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_66.xpm", &data->frames[65].width ,&data->frames[65].height);
	data->frames[66].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_67.xpm", &data->frames[66].width ,&data->frames[66].height);
	data->frames[67].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_68.xpm", &data->frames[67].width ,&data->frames[67].height);
	data->frames[68].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_69.xpm", &data->frames[68].width ,&data->frames[68].height);
	data->frames[69].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_70.xpm", &data->frames[69].width ,&data->frames[69].height);
	data->frames[70].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_71.xpm", &data->frames[70].width ,&data->frames[70].height);
	data->frames[71].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_72.xpm", &data->frames[71].width ,&data->frames[71].height);
	data->frames[72].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_73.xpm", &data->frames[72].width ,&data->frames[72].height);
	data->frames[73].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_74.xpm", &data->frames[73].width ,&data->frames[73].height);
	data->frames[74].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_75.xpm", &data->frames[74].width ,&data->frames[74].height);
	data->frames[75].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_76.xpm", &data->frames[75].width ,&data->frames[75].height);
	data->frames[76].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_77.xpm", &data->frames[76].width ,&data->frames[76].height);
	data->frames[77].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_78.xpm", &data->frames[77].width ,&data->frames[77].height);
	data->frames[78].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_79.xpm", &data->frames[78].width ,&data->frames[78].height);
	data->frames[79].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_80.xpm", &data->frames[79].width ,&data->frames[79].height);
	data->frames[80].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_81.xpm", &data->frames[80].width ,&data->frames[80].height);
	data->frames[81].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_82.xpm", &data->frames[81].width ,&data->frames[81].height);
	data->frames[82].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_83.xpm", &data->frames[82].width ,&data->frames[82].height);
	data->frames[83].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_84.xpm", &data->frames[83].width ,&data->frames[83].height);
	data->frames[84].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_85.xpm", &data->frames[84].width ,&data->frames[84].height);
	data->frames[85].img = mlx_xpm_file_to_image(data->mlx_ptr, "Frames/frame_86.xpm", &data->frames[85].width ,&data->frames[85].height);
	//!	All Of This Should Do It In While Loop____________________
	return (0);
}
