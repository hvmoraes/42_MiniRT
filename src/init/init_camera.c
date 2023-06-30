/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:53:04 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/29 16:52:19 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	set_viewport(void)
{
	g_data.viewport.distance = 1;
	g_data.viewport.width = 2 * g_data.viewport.distance * tan(to_rad(g_data.camera.fov));
	g_data.viewport.height = g_data.viewport.width * HEIGHT / WIDTH;
}

/**
 * @brief Init Camera's info
 * 
 * @param line 
 */
void	init_camera(char **line)
{
	if (line_fields(line) != 3)
		handle_error("Camera's usage: C [coords: x,y,z] [normal: x,y,z] fov");
	if (!check_coords(line[1], &g_data.camera.coor))
		handle_error("Camera's coordinates have to be in format [x,y,z]");
	if (!check_normal(line[2], &g_data.camera.normal))
		handle_error("Camera's coordinates have to be in format [(x range: -1,1),(y range: -1,1),(z range: -1,1)]");
	g_data.camera.fov = ft_atod(line[3]);
	if (g_data.camera.fov < 0 ||  g_data.camera.fov > 180)
		handle_error("Camera's FOV has to be in range [0,180]");
	setup_viewport();
}
