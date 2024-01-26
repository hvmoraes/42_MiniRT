/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:40:34 by mmirzaie          #+#    #+#             */
/*   Updated: 2024/01/26 16:19:26 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	get_closert(t_vec2d hits, t_hitable *map, t_vec3d rayorigin, t_ray ray)
{
	t_vec3d	p1;
	t_vec3d	p2;
	float	y1;
	float	y2;

	p1 = t_vec3d_add(rayorigin, t_vec3d_scale(ray.dir, hits.y));
	y1 = p1.y - map->point.y;
	if (y1 < -map->height / 2.0f || y1 > map->height / 2.0f)
		hits.y = __FLT_MAX__;
	else
		return (hits.y);
	p2 = t_vec3d_add(rayorigin, t_vec3d_scale(ray.dir, hits.x));
	y2 = p2.y - map->point.y;
	if (y2 < -map->height / 2.0f || y2 > map->height / 2.0f)
		hits.x = __FLT_MAX__;
	else
		return (hits.x);
	return (__FLT_MAX__);
}

float	ft_cylinder(t_hitable *map, t_ray ray)
{
	t_vec3d		quad;
	float		discriminant;
	t_vec2d		hits;
	t_vec3d		rayorigin;

	rayorigin = t_vec3d_sub(ray.orig, map->point);
	quad.x = (ray.dir.x * ray.dir.x) + (ray.dir.z * ray.dir.z);
	quad.y = 2.0f * (rayorigin.x * ray.dir.x + rayorigin.z * ray.dir.z);
	quad.z = (rayorigin.x * rayorigin.x) + (rayorigin.z * rayorigin.z)
		- (map->radius2);
	discriminant = quad.y * quad.y - 4.0f * quad.x * quad.z;
	if (discriminant >= 0.0f)
	{
		hits.x = (-quad.y + sqrt(discriminant)) / (2.0f * quad.x);
		hits.y = (-quad.y - sqrt(discriminant)) / (2.0f * quad.x);
		if (hits.y > 0.001f)
			return (get_closert(hits, map, rayorigin, ray));
	}
	return (__FLT_MAX__);
}
