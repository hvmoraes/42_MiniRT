/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:52:33 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/29 16:13:47 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Init Window
 * 
 * @return void 
 */
void	init_scene(void)
{
	g_data.mlx.width = WIDTH;
	g_data.mlx.height = HEIGHT;
	g_data.mlx.mlx = mlx_init();
	g_data.mlx.win = mlx_new_window(g_data.mlx.mlx,
			g_data.mlx.width, g_data.mlx.height, "MiniRT");
	g_data.mlx.img = mlx_new_image(g_data.mlx.mlx,
			g_data.mlx.width, g_data.mlx.height);
	g_data.mlx.addr = mlx_get_data_addr(g_data.mlx.img,
			&(g_data.mlx.bpp), &(g_data.mlx.line_len),
			&(g_data.mlx.endian));
}
