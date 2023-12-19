/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:53:04 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/12/19 10:26:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Cooresponds point (x,y) to viewport
 * 
 * @param x 
 * @param y 
 * @param point 
 */
void	canvas_viewport(int x, int y, t_coor3 *point)
{
	t_coor3	u;
	t_coor3	v;

	set_vectors(&u, &v);
	point->x = g_data.camera.coor.x + g_data.camera.normal.x + \
	(((double)x / WIDTH) * (g_data.viewport.width / \
	vec_size(u))) * u.x + (((double)y / HEIGHT) \
	* (g_data.viewport.height / vec_size(v))) * v.x;
	point->y = g_data.camera.coor.y + g_data.camera.normal.y + \
	(((double)x / WIDTH) * (g_data.viewport.width / \
	vec_size(u))) * u.y + (((double)y / HEIGHT) \
	* (g_data.viewport.height / vec_size(v))) * v.y;
	point->z = g_data.camera.coor.z + g_data.camera.normal.z + \
	(((double)x / WIDTH) * (g_data.viewport.width / \
	vec_size(u))) * u.z + (((double)y / HEIGHT) \
	* (g_data.viewport.height / vec_size(v))) * v.z;
}

/**
 * @brief Init the viewport info: distance, width and height
 * 
 */
void	set_viewport(void)
{
	double	aspect_ratio;

	g_data.viewport.distance = 1;
	aspect_ratio = (double)HEIGHT / (double)WIDTH;
	g_data.viewport.width = 2 * g_data.viewport.distance
		* tan(to_rad(g_data.camera.fov / 2));
	g_data.viewport.height = g_data.viewport.width / aspect_ratio;
}

/**
 * @brief Init Camera's info
 * 
 * @param line 
 */
int	init_camera(char **line)
{
	if (line_fields(line) != 4)
		return (parse_error("Camera's usage: C "
				"[coords: x,y,z] [normal: x,y,z] fov"));
	if (!check_coords(line[1], &g_data.camera.coor))
		return (parse_error("Camera's coordinates have to be a valid number"));
	if (!check_normal(line[2], &g_data.camera.normal))
		return (parse_error("Camera's normal coordinates have to be in format "
				"[(x range: -1,1),(y range: -1,1),(z range: -1,1)]"));
	g_data.camera.fov = ft_atod(line[3]);
	if (g_data.camera.fov < 0 || g_data.camera.fov > 180 || !is_number(line[3]))
		return (parse_error("Camera's FOV has to be in range [0,180]"));
	set_viewport();
	return (1);
}
